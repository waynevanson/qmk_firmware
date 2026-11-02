{
  description = "QMK build environment for the Charybdis 3x6";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs =
    { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};

      # Change to "bastardkb/charybdis/3x6/blackpill" if you use a Blackpill.
      keyboard = "bastardkb/charybdis/3x6/elitec";
      keymap = "waynevanson";

      # qmk's propagated inputs contain make, avr-gcc, dfu-programmer, etc.
      qmkPath = pkgs.lib.makeBinPath (
        [
          pkgs.qmk
          pkgs.git
        ]
        ++ pkgs.qmk.propagatedBuildInputs
      );

      mkQmkApp =
        name: args:
        {
          type = "app";
          program = toString (
            pkgs.writeShellScript "qmk-${name}" ''
              set -euo pipefail
              export PATH="${qmkPath}:$PATH"
              cd "$(git rev-parse --show-toplevel)"
              export QMK_HOME="$PWD"
              exec qmk ${args}
            ''
          );
        };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = [
          pkgs.qmk
          pkgs.git
        ];

        shellHook = ''
          export QMK_HOME="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
          echo "QMK_HOME=$QMK_HOME"
        '';
      };

      apps.${system} = {
        compile = mkQmkApp "compile" "compile -kb ${keyboard} -km ${keymap}";
        flash = mkQmkApp "flash" "flash -kb ${keyboard} -km ${keymap}";
      };

      formatter.${system} = pkgs.nixfmt-rfc-style;
    };
}

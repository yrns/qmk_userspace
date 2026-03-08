{pkgs ? import <nixpkgs> {}}: let
  inherit (pkgs) mkShell qmk;
in
  mkShell {
    buildInputs = [qmk pkgs.clang-tools];
    shellHook = ''
      export QMK_USERSPACE="$PWD"
    '';
  }

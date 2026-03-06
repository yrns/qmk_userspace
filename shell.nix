{pkgs ? import <nixpkgs> {}}: let
  inherit (pkgs) mkShell qmk;
in
  mkShell {
    buildInputs = [qmk];
    shellHook = ''
      export QMK_USERSPACE="$PWD"
    '';
  }

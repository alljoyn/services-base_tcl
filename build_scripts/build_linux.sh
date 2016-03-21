#!/bin/bash
set -e # fail fast
SCRIPT_DIR=$( dirname "${BASH_SOURCE[0]}" )
echo "Directory: $SCRIPT_DIR"

while getopts 'V:W:S:' opts; do
   case ${opts} in
      V) export VARIANT=${OPTARG} ;;
      W) export WS=${OPTARG} ;;
      S) export SERVICE=${OPTARG} ;; # TODO explict service build
      *) echo "Invalid argument: ${OPTARG}"; #exit 1  # illegal option
   esac
done

set -x # echo commands

# build core
pushd core/ajtcl
scons -c VARIANT=$VARIANT WS=$WS
scons VARIANT=$VARIANT WS=$WS
popd

# build service
pushd services/base_tcl
#pushd services/base_tcl/$SERVICE # TODO explict service build
scons -c VARIANT=$VARIANT WS=$WS docs=html
scons VARIANT=$VARIANT WS=$WS docs=html
popd

# packaging
$SCRIPT_DIR/build_linux_package.sh




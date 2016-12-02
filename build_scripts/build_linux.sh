#!/usr/bin/env bash

# # 
#    Copyright (c) 2016 Open Connectivity Foundation and AllJoyn Open
#    Source Project Contributors and others.
#    
#    All rights reserved. This program and the accompanying materials are
#    made available under the terms of the Apache License, Version 2.0
#    which accompanies this distribution, and is available at
#    http://www.apache.org/licenses/LICENSE-2.0

#

set -eux

function finish {
   popd
}
trap finish EXIT

SCRIPT_DIR=$( dirname "${BASH_SOURCE[0]}" )
pushd "${SCRIPT_DIR}"

while getopts 'V:W:S:' opts; do
   case ${opts} in
      V) export VARIANT=${OPTARG} ;;
      W) export WS=${OPTARG} ;;
      S) export SERVICE=${OPTARG} ;; # TODO explict service build
      *) echo "Invalid argument: ${OPTARG}"; #exit 1  # illegal option
   esac
done

if [[ -z "${AJ_ROOT+notempty}" ]]; then
   AJ_ROOT="$(pwd)/../../.."
fi

if [[ -z "${VARIANT+notempty}" ]]; then
    VARIANT="debug"
fi

if [[ -z "${WS+notempty}" ]]; then
    WS="off"
fi

# build core
pushd "${AJ_ROOT}/core/ajtcl"
scons -c VARIANT="$VARIANT" WS="$WS"
scons VARIANT="$VARIANT" WS="$WS" --config=force
popd

# build service
pushd "${AJ_ROOT}/services/base_tcl"
#pushd services/base_tcl/$SERVICE # TODO explict service build
scons -c VARIANT="$VARIANT" WS="$WS" docs=html
scons VARIANT="$VARIANT" WS="$WS" docs=html --config=force
popd

# packaging
./build_linux_package.sh
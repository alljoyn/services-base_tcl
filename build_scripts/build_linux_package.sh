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
# This script collects all the pieces to make the SDK for the cpp builds

set -eux

env | sort

if [[ -z "${AJ_ROOT+notempty}" ]]; then
   AJ_ROOT="$(pwd)/../../.."
fi

[ -d "${WORKSPACE}" ] || { echo "WORKSPACE does not exist"; exit 1; }

zip_base="alljoyn-tcl-service-framework-${BUILD_VERSION}-linux-x86_64-sdk-${variant}"
sdk_dir="${WORKSPACE}/${zip_base}"

rm -rf $sdk_dir
mkdir -p $sdk_dir

##
## Generate Doxygen docs
##
doxyfile=Doxyfile

pushd "${AJ_ROOT}/services/base_tcl"
#pushd services/base_tcl/$SERVICE # todo
rm -rf html dist/docs/html
doxygen $doxyfile ### 2> doxy.out >> /dev/null
mkdir -p dist/docs || : ok
mv -f html dist/docs/html
cp -rp dist/*    $sdk_dir
popd

pushd "${WORKSPACE}"
rm -rf $zip_base.zip
zip -q -r $zip_base.zip $zip_base
md5sum $zip_base.zip > md5sum-$zip_base.txt
popd
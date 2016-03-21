#!/bin/bash -ex
# This script collects all the pieces to make the SDK for the cpp builds

env | sort

zip_base=alljoyn-tcl-service-framework-${BUILD_VERSION}-linux-x86_64-sdk-$variant
sdk_dir=$WORKSPACE/$zip_base

rm -rf $sdk_dir
mkdir -p $sdk_dir

##
## Generate Doxygen docs
##
doxyfile=Doxyfile

pushd services/base_tcl
#pushd services/base_tcl/$SERVICE # todo
rm -rf html dist/docs/html
doxygen $doxyfile ### 2> doxy.out >> /dev/null
mkdir -p dist/docs || : ok
mv -f html dist/docs/html
cp -rp dist/*    $sdk_dir
popd

rm -rf $zip_base.zip
zip -q -r $zip_base.zip $zip_base
md5sum $zip_base.zip > md5sum-$zip_base.txt

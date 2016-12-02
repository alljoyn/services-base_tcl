#!/bin/bash
# # 
#    Copyright (c) 2016 Open Connectivity Foundation and AllJoyn Open
#    Source Project Contributors and others.
#    
#    All rights reserved. This program and the accompanying materials are
#    made available under the terms of the Apache License, Version 2.0
#    which accompanies this distribution, and is available at
#    http://www.apache.org/licenses/LICENSE-2.0

#
echo "Generating code for" "$@"

INITIAL_DIR=`pwd` # Save current dir
cd `dirname $0`       # Go to script dir

python generateCPSApp.py "$@" -p ../../../sample_apps/ServerSample/ -t ../CPSControlleeTester/
retval=$?

cd ${INITIAL_DIR}

exit $retval


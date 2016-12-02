/******************************************************************************
 *  * 
 *    Copyright (c) 2016 Open Connectivity Foundation and AllJoyn Open
 *    Source Project Contributors and others.
 *    
 *    All rights reserved. This program and the accompanying materials are
 *    made available under the terms of the Apache License, Version 2.0
 *    which accompanies this distribution, and is available at
 *    http://www.apache.org/licenses/LICENSE-2.0

 ******************************************************************************/

#include <stdlib.h>
#include <aj_target.h>
#include <aj_debug.h>
#include <ServerSampleUtil.h>
#include "PropertyStoreOEMProvisioning.h"
#include <alljoyn/services_common/PropertyStore.h>

/**
 * Allows the DeviceName to be set dynamically from the environment
 */
void ServerSample_SetupEnv()
{
    char* deviceName = getenv("AJ_DEVICE_NAME");
    if (deviceName) {
        AJ_AlwaysPrintf(("Setting DeviceName from env to: %s\n", deviceName));
        /* set the DeviceName for the default language */
        AJSVC_PropertyStore_SetValueForLang(AJSVC_PROPERTY_STORE_DEVICE_NAME, AJSVC_PropertyStore_GetCurrentDefaultLanguageIndex(), deviceName);
    }
}
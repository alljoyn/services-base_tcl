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

#include <alljoyn/controlpanel/Common/HttpControl.h>
#include <alljoyn/controlpanel/Definitions.h>
#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>

void initializeHttpControl(HttpControl* httpControl)
{
    httpControl->url = NULL;
    httpControl->getUrl = NULL;
}

AJ_Status marshalHttpControlUrl(HttpControl* httpControl, AJ_Message* reply, uint16_t language)
{
    if (httpControl->getUrl == 0 && httpControl->url == 0) {
        return AJ_ERR_UNEXPECTED;
    }
    return AJ_MarshalArgs(reply, PROPERTY_TYPE_URL_SIG, httpControl->getUrl ? httpControl->getUrl() : httpControl->url);
}
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

#ifndef CONTROLPANELCLIENT_H_
#define CONTROLPANELCLIENT_H_

#include "ControlPanelClientGenerated.h"
#include "alljoyn/controlpanel/ControlPanelService.h"
#include "alljoyn/controlpanel/Definitions.h"
#include "alljoyn/services_common/ServicesCommon.h"
#include "aj_debug.h"

/**
 * Static non consts.
 */
char announceSender[16];

void CPS_Init();

AJ_Status CPS_StartService(AJ_BusAttachment* bus, const char* daemonName, uint32_t timeout, uint8_t connected);

void MakeMethodCall(uint32_t sessionId);

void CPS_IdleConnectedHandler(AJ_BusAttachment*bus);

AJSVC_ServiceStatus CPS_NotifySessionAccepted(uint32_t sessionId, const char*sender);

AJSVC_ServiceStatus CPS_MessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status*msgStatus);

void CPS_Finish();

#endif //end CONTROLPANELCLIENT_H_
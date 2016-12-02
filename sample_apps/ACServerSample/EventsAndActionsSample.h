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

#ifndef EVENTSANDACTIONS_H_
#define EVENTSANDACTIONS_H_

#include <alljoyn.h>

AJ_Status EventsAndActions_Init(const char* const* descriptionLanguages);

void EventsAndActions_DoWork(AJ_BusAttachment* busAttachment);

AJ_Status EventsAndActions_Finish(AJ_BusAttachment* busAttachment);

AJSVC_ServiceStatus EventsAndActionsMessageProcessor(AJ_BusAttachment* busAttachment, AJ_Message* msg, AJ_Status* msgStatus);

#endif /* EVENTSANDACTIONS_H_ */
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

#ifndef CONTROLPANEL_H_
#define CONTROLPANEL_H_

#include <alljoyn.h>
#include "ControlPanelGenerated.h"

AJ_Status Controlee_Init();

void Controlee_DoWork();

AJ_Status Controlee_Finish(AJ_BusAttachment* busAttachment);
#endif /* CONTROLPANEL_H_ */
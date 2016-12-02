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

#ifndef _CONFIGSAMPLE_H_
#define _CONFIGSAMPLE_H_

/** @defgroup Config Sample
 *
 *  @{
 */

#include <ajtcl/alljoyn.h>

/*
 * Config Sample API
 */

/**
 * on init service
 */
AJ_Status Config_Init();

/**
 * on idle - no messages
 * @param bus
 */
void Config_DoWork(AJ_BusAttachment* bus);

/**
 * on finish service
 * @param bus
 */
AJ_Status Config_Finish(AJ_BusAttachment* bus);

/** @} */
 #endif // _CONFIGSAMPLE_H_
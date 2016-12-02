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

#ifndef _ONBOARDINGSAMPLE_H_
#define _ONBOARDINGSAMPLE_H_

/** @defgroup Onboarding Sample
 *
 *  @{
 */

#include <ajtcl/alljoyn.h>

/**
 * on init
 */
AJ_Status Onboarding_Init(const char* deviceManufactureName, const char* deviceProductName);

/**
 * on idle connected
 * @param bus
 */
void Onboarding_DoWork(AJ_BusAttachment* busAttachment);

/**
 * on finish
 */
AJ_Status Onboarding_Finish();

/** @} */
 #endif // _ONBOARDINGSAMPLE_H_
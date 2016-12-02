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

#ifndef _NOTIFICATIONPRODUCERSAMPLE_H_
#define _NOTIFICATIONPRODUCERSAMPLE_H_

#include <ajtcl/alljoyn.h>

/*
 * Functions to be implemented by Application
 */

/**
 * Initialize the Notification Service Producer
 * @return status
 */
AJ_Status NotificationProducer_Init();

/**
 * If idle, do work
 * @param busAttachment
 */
void NotificationProducer_DoWork(AJ_BusAttachment* busAttachment);

/**
 * Finish Producer - called when bus disconnects
 * @return status
 */
AJ_Status NotificationProducer_Finish();

#endif /* _NOTIFICATIONPRODUCERSAMPLE_H_ */
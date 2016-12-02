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

#ifndef _NOTIFICATIONCONSUMERSAMPLE_H_
#define _NOTIFICATIONCONSUMERSAMPLE_H_

#include <ajtcl/alljoyn.h>

#define CONSUMER_ACTION_NOTHING         0
#define CONSUMER_ACTION_DISMISS         1

/*
 * Functions that the application needs to implement
 */

/**
 * Initialize the Notification Service Consumer
 * @return status
 */
AJ_Status NotificationConsumer_Init();

/**
 * If idle, do work
 * @param busAttachment
 */
void NotificationConsumer_DoWork(AJ_BusAttachment* busAttachment);

/**
 * Finish Consumer - called when bus disconnects
 * @return status
 */
AJ_Status NotificationConsumer_Finish();

#endif /* _NOTIFICATIONCONSUMERSAMPLE_H_ */

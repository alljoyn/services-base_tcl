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

#ifndef PRODUCER_SAMPLE_UTIL_H_
#define PRODUCER_SAMPLE_UTIL_H_

#include <alljoyn.h>

void Producer_SetupEnv(uint8_t* inputMode);
void Producer_GetNotificationFromUser(AJNS_NotificationContent* notificationContent, uint16_t* messageType, uint32_t* ttl, uint32_t* nextMessageTime);
void Producer_GetShouldDeleteNotificationFromUser(AJ_BusAttachment* busAttachment, uint8_t* delMsg, uint16_t* delMsgType);
void Producer_FreeNotification(AJNS_NotificationContent* notificationContent);
void Producer_ReadConfigFromEnv(uint8_t* producerEnabled, AJNS_NotificationContent* notificationContent,
                                uint32_t* messagesInterval, uint8_t* intervalTypeRandom, uint32_t* initialIntervalOffset,
                                uint16_t* messagePriority, uint8_t* priorityTypeRandom, uint32_t* messageTtl);

#endif /* PRODUCER_SAMPLE_UTIL_H_ */

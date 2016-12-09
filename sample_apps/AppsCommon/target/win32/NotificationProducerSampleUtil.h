/******************************************************************************
 * Copyright (c) 2016 Open Connectivity Foundation (OCF) and AllJoyn Open
 *    Source Project (AJOSP) Contributors and others.
 *
 *    SPDX-License-Identifier: Apache-2.0
 *
 *    All rights reserved. This program and the accompanying materials are
 *    made available under the terms of the Apache License, Version 2.0
 *    which accompanies this distribution, and is available at
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Copyright 2016 Open Connectivity Foundation and Contributors to
 *    AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for
 *    any purpose with or without fee is hereby granted, provided that the
 *    above copyright notice and this permission notice appear in all
 *    copies.
 *
 *     THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 *     WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 *     WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 *     AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 *     DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 *     PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 *     TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 *     PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef PRODUCER_SAMPLE_UTIL_H_
#define PRODUCER_SAMPLE_UTIL_H_

#include <alljoyn.h>

void Producer_SetupEnv(uint8_t* inputMode);
void Producer_GetNotificationFromUser(AJNS_NotificationContent* notificationContent, uint16_t* messageType, uint32_t* ttl, uint32_t* nextMessageTime);
void Producer_GetShouldDeleteNotificationFromUser(AJ_BusAttachment* busAttachment, uint8_t* delMsg, uint16_t* delMsgType);
void Producer_FreeNotification(AJNS_NotificationContent* notificationContent);
/* Producer_ReadConfigFromEnv not implemented */
#define Producer_ReadConfigFromEnv(...) do { } while (0)

#endif /* PRODUCER_SAMPLE_UTIL_H_ */

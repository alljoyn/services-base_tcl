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

/**
 * Per-module definition of the current module for debug logging.  Must be defined
 * prior to first inclusion of aj_debug.h.
 * The corresponding flag dbgAJSVCAPP is defined in the containing sample app.
 */
#define AJ_MODULE AJSVCAPP
#include <aj_debug.h>

#include <alljoyn.h>
#include <NotificationProducerSample.h>
#include <alljoyn/notification/NotificationProducer.h>

#include "ControlPanelProvided.h"

#ifndef NDEBUG
extern AJ_EXPORT uint8_t dbgAJSVCAPP;
#endif

/**
 * Static consts - sample application specific
 */
const static char* langEng  = "en";
const static char* helloEng = "Hello AJL World";

#define NUM_TEXTS   1
static AJNS_DictionaryEntry textToSend[NUM_TEXTS];

#define NUM_CUSTOMS 0
#define NUM_RICH_AUDIO 0
static AJNS_NotificationContent notificationContent;

/**
 * Initial the Notifications that will be used during this sample app
 */
static void InitNotificationContent()
{
    notificationContent.numCustomAttributes = NUM_CUSTOMS;

    notificationContent.numTexts = NUM_TEXTS;
    textToSend[0].key   = langEng;
    textToSend[0].value = helloEng;
    notificationContent.texts = textToSend;

    notificationContent.numAudioUrls = NUM_RICH_AUDIO;

}

/**
 * Initialize service
 */
AJ_Status NotificationProducer_Init()
{
    AJ_Status status;

    InitNotificationContent();
    status = AJNS_Producer_Start();

    return status;
}

/**
 * Meant to simulate scenario where sometimes Notifications are set when
 * Send Notification is called and sometimes not.
 */
void NotificationProducer_DoWork(AJ_BusAttachment* busAttachment)
{
    if (isThereANotificationToSend() > 0) {
        notificationContent.numTexts = NUM_TEXTS;
        textToSend[0].key   = langEng;
        textToSend[0].value = getNotificationString();
        notificationContent.controlPanelServiceObjectPath = getNotificationActionObjPath();

        AJ_AlwaysPrintf(("About to send Notification ==> %s with action [%s]\n", textToSend[0].value, (notificationContent.controlPanelServiceObjectPath == NULL ? "NULL" : notificationContent.controlPanelServiceObjectPath)));
        AJNS_Producer_SendNotification(busAttachment, &notificationContent, AJNS_NOTIFICATION_MESSAGE_TYPE_INFO, AJNS_NOTIFICATION_TTL_MIN, NULL);
    }
}

AJ_Status NotificationProducer_Finish(AJ_BusAttachment* busAttachment)
{
    return AJ_OK;
}
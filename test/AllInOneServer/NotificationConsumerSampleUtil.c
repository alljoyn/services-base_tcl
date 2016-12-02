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

#include <ajtcl/aj_target.h>
#include <ajtcl/aj_status.h>
#include <stdlib.h>
#include <ajtcl/services/NotificationConsumer.h>
#include "NotificationConsumerSampleUtil.h"

#ifdef _WIN32
#define snprintf _snprintf
#endif

#define BUF_SIZE 500

static uint8_t GetCmdLine(char* buf, size_t num)
{
    while (AJ_GetCmdLine(buf, num) == NULL) {
    }
    return (strlen(buf) > 0);
}

void Consumer_GetActionFromUser(uint8_t* action)
{
    char buf[BUF_SIZE];
    uint8_t defaultAction = *action;
    AJ_StartReadFromStdIn();
    AJ_Printf("Please enter an action to perform on the recently received notification\n\t0=Nothing,\n\t1=Dismiss.\n");
    AJ_Printf("Empty string or invalid input will default to %u\n", defaultAction);
    if (GetCmdLine(buf, BUF_SIZE)) {
        char stringType[4]; // Maximum decimal value for uint8_t is 255 which is 3 characters long
        *action = (uint8_t)atoi(buf);
        snprintf(stringType, 4, "%u", *action);
        if (!(strcmp(buf, stringType) == 0)) {             //they do not match, it is not int
            AJ_Printf("Action is not an integer value. Defaulting to %u\n", defaultAction);
            *action = defaultAction;
        }
    }
    AJ_StopReadFromStdIn();
}
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

#include <alljoyn/controlpanel/Common/DateTimeUtil.h>
#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>

AJ_Status marshalDatePropertyValue(DatePropertyValue* datePropertyValue, AJ_Message* reply)
{
    AJ_Status status;
    AJ_Arg structArg;

    status = AJ_MarshalVariant(reply, DATE_PROPERTY_SIG);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalContainer(reply, &structArg, AJ_ARG_STRUCT);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalArgs(reply, "q(qqq)", DATE_PROPERTY, datePropertyValue->mDay, datePropertyValue->month, datePropertyValue->fullYear);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &structArg);
}

AJ_Status marshalTimePropertyValue(TimePropertyValue* timePropertyValue, AJ_Message* reply)
{
    AJ_Status status;
    AJ_Arg structArg;

    status = AJ_MarshalVariant(reply, TIME_PROPERTY_SIG);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalContainer(reply, &structArg, AJ_ARG_STRUCT);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalArgs(reply, "q(qqq)", TIME_PROPERTY, timePropertyValue->hour, timePropertyValue->minute, timePropertyValue->second);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &structArg);
}

AJ_Status unmarshalDatePropertyValue(DatePropertyValue* datePropertyValue, AJ_Message* message)
{
    AJ_Status status;
    AJ_Arg structArg;
    uint16_t widgetType;

    status = AJ_UnmarshalContainer(message, &structArg, AJ_ARG_STRUCT);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_UnmarshalArgs(message, "q(qqq)", &widgetType, &datePropertyValue->mDay, &datePropertyValue->month, &datePropertyValue->fullYear);
    if (status != AJ_OK) {
        return status;
    }
    if (widgetType != DATE_PROPERTY) {
        return AJ_ERR_UNEXPECTED;
    }

    return AJ_UnmarshalCloseContainer(message, &structArg);
}

AJ_Status unmarshalTimePropertyValue(TimePropertyValue* timePropertyValue, AJ_Message* message)
{
    AJ_Status status;
    AJ_Arg structArg;
    uint16_t widgetType;

    status = AJ_UnmarshalContainer(message, &structArg, AJ_ARG_STRUCT);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_UnmarshalArgs(message, "q(qqq)", &widgetType, &timePropertyValue->hour, &timePropertyValue->minute, &timePropertyValue->second);
    if (status != AJ_OK) {
        return status;
    }
    if (widgetType != TIME_PROPERTY) {
        return AJ_ERR_UNEXPECTED;
    }

    return AJ_UnmarshalCloseContainer(message, &structArg);
}

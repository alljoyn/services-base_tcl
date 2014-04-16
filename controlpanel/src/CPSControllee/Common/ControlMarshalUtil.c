/******************************************************************************
 * Copyright (c) 2013 - 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>
#include <alljoyn/controlpanel/Common/BaseWidget.h>

#define ROOT_INTERFACE_VERSION 1

AJ_Status AddHints(AJ_Message* reply, const uint16_t hints[], uint16_t numHints)
{
    AJ_Status status;
    AJ_Arg arrayArg;

    status = AJ_MarshalContainer(reply, &arrayArg, AJ_ARG_ARRAY);
    if (status != AJ_OK) {
        return status;
    }
    uint16_t cnt;
    for (cnt = 0; cnt < numHints; cnt++)
        status = AJ_MarshalArgs(reply, "q", hints[cnt]);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &arrayArg);
}

AJ_Status AddConstraintValue(AJ_Message* reply, const char* sig, const void* value, const char* displayValue)
{
    return AJ_MarshalArgs(reply, "(vs)", sig, *((void**)value), displayValue);
}

AJ_Status AddConstraintRange(AJ_Message* reply, const char* valueSig, const void* min, const void* max, const void* increment)
{
    return AJ_MarshalArgs(reply, "(vvv)", valueSig, *((void**)min), valueSig, *((void**)max), valueSig, *((void**)increment));
}

AJ_Status StartComplexOptionalParam(AJ_Message* reply, AJ_Arg* arg, uint16_t key, const char* sig)
{
    AJ_Status status;

    status = AJ_MarshalContainer(reply, arg, AJ_ARG_DICT_ENTRY);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalArgs(reply, "q", key);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalVariant(reply, sig);
}

AJ_Status AddBasicOptionalParam(AJ_Message* reply, uint16_t key, const char* sig, const void* value)
{
    return AJ_MarshalArgs(reply, "{qv}", key, sig, *((void**)value));
}

AJ_Status AddPropertyForGetAll(AJ_Message* reply, char* key, const char* sig,
                               BaseWidget* widget, uint16_t language, MarshalWidgetFptr functionPtr)
{
    AJ_Status status;
    AJ_Arg dictArg;

    status = AJ_MarshalContainer(reply, &dictArg, AJ_ARG_DICT_ENTRY);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalArgs(reply, "s", key);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalVariant(reply, sig);
    if (status != AJ_OK) {
        return status;
    }
    status = functionPtr(widget, reply, language);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &dictArg);
}

AJ_Status MarshalAllRootProperties(AJ_Message* reply)
{
    AJ_Status status;
    AJ_Arg rootGetAllArray;
    AJ_Arg dictArg;

    status = AJ_MarshalContainer(reply, &rootGetAllArray, AJ_ARG_ARRAY);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalContainer(reply, &dictArg, AJ_ARG_DICT_ENTRY);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalArgs(reply, "s", PROPERTY_TYPE_VERSION_NAME);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalVariant(reply, PROPERTY_TYPE_VERSION_SIG);
    if (status != AJ_OK) {
        return status;
    }
    status = MarshalVersionRootProperties(reply);
    if (status != AJ_OK) {
        return status;
    }
    status = AJ_MarshalCloseContainer(reply, &dictArg);
    if (status != AJ_OK) {
        return status;
    }
    return AJ_MarshalCloseContainer(reply, &rootGetAllArray);
}

AJ_Status MarshalVersionRootProperties(AJ_Message* reply)
{
    return AJ_MarshalArgs(reply, PROPERTY_TYPE_VERSION_SIG, ROOT_INTERFACE_VERSION);
}

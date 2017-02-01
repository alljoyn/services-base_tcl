/******************************************************************************
 *    Copyright (c) Open Connectivity Foundation (OCF), AllJoyn Open Source
 *    Project (AJOSP) Contributors and others.
 *    
 *    SPDX-License-Identifier: Apache-2.0
 *    
 *    All rights reserved. This program and the accompanying materials are
 *    made available under the terms of the Apache License, Version 2.0
 *    which accompanies this distribution, and is available at
 *    http://www.apache.org/licenses/LICENSE-2.0
 *    
 *    Copyright (c) Open Connectivity Foundation and Contributors to AllSeen
 *    Alliance. All rights reserved.
 *    
 *    Permission to use, copy, modify, and/or distribute this software for
 *    any purpose with or without fee is hereby granted, provided that the
 *    above copyright notice and this permission notice appear in all
 *    copies.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 *    WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 *    WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 *    AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 *    DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 *    PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 *    TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 *    PERFORMANCE OF THIS SOFTWARE.
******************************************************************************/

#include <ajtcl/services/Widgets/LabelWidget.h>
#include <ajtcl/services/Definitions.h>
#include <ajtcl/services/Common/ControlMarshalUtil.h>

void initializeLabelWidget(LabelWidget* widget)
{
    initializeBaseWidget(&widget->base);
    widget->label = NULL;
    widget->getLabel = NULL;

    widget->base.marshalAllProp = &marshalAllLabelProperties;
}

AJ_Status marshalLabelLabel(LabelWidget* widget, AJ_Message* reply, uint16_t language)
{
    if (language >= widget->base.numLanguages) {
        return AJ_ERR_UNEXPECTED;
    }

    if (widget->getLabel) {
        return AJ_MarshalArgs(reply, PROPERTY_TYPE_LABEL_SIG, widget->getLabel(widget, language));
    }
    return AJ_MarshalArgs(reply, PROPERTY_TYPE_LABEL_SIG, widget->label[language]);
}

AJ_Status marshalAllLabelProperties(BaseWidget* widget, AJ_Message* reply, uint16_t language)
{
    AJ_Status status;
    AJ_Arg labelGetAllArray;

    status = AJ_MarshalContainer(reply, &labelGetAllArray, AJ_ARG_ARRAY);
    if (status != AJ_OK) {
        return status;
    }

    status = marshalAllBaseProperties(widget, reply, language);
    if (status != AJ_OK) {
        return status;
    }

    status = AddPropertyForGetAll(reply, PROPERTY_TYPE_LABEL_NAME, PROPERTY_TYPE_LABEL_SIG, widget, language, (MarshalWidgetFptr)marshalLabelLabel);
    if (status != AJ_OK) {
        return status;
    }

    status = AddPropertyForGetAll(reply, PROPERTY_TYPE_OPTPARAMS_NAME, PROPERTY_TYPE_OPTPARAMS_SIG, widget, language, marshalOnlyBaseOptParam);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &labelGetAllArray);
}
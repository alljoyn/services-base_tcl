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

#include <alljoyn/controlpanel/Widgets/LabelWidget.h>
#include <alljoyn/controlpanel/Definitions.h>
#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>

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
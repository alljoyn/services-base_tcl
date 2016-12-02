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

#include <ajtcl/services/Common/ConstraintList.h>
#include <ajtcl/services/Common/ControlMarshalUtil.h>
#include <ajtcl/services/Widgets/PropertyWidget.h>

AJ_Status marshalConstraintList(BaseWidget* widget, ConstraintList* constraints, AJ_Message* reply, uint16_t numConstraints,
                                const char* signature, uint16_t language)
{
    AJ_Status status;
    AJ_Arg arrayArg, opParams;
    uint16_t cnt;
    PropertyWidget* propWidget = (PropertyWidget*)widget;
    const void* value;
    const char* display;

    status = StartComplexOptionalParam(reply, &opParams, PROPERTY_CONSTRAINT_LIST, PROPERTY_CONSTRAINT_LIST_SIG);
    if (status != AJ_OK) {
        return status;
    }

    status = AJ_MarshalContainer(reply, &arrayArg, AJ_ARG_ARRAY);
    if (status != AJ_OK) {
        return status;
    }

    for (cnt = 0; cnt < numConstraints; cnt++) {
        if (propWidget->optParams.getConstraint) {
            display = propWidget->optParams.getConstraint(propWidget, cnt, &value, language);
        } else if (constraints[cnt].getDisplay != 0) {
            value = constraints[cnt].value;
            display = constraints[cnt].getDisplay(language);
        } else {
            value = constraints[cnt].value;
            display = constraints[cnt].display[language];
        }
        status = AddConstraintValue(reply, signature, value, display);
        if (status != AJ_OK) {
            return status;
        }
    }

    status = AJ_MarshalCloseContainer(reply, &arrayArg);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &opParams);
}
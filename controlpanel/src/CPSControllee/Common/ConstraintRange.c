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

#include <alljoyn/controlpanel/Common/ConstraintRange.h>
#include <alljoyn/controlpanel/Common/ControlMarshalUtil.h>

void initializeConstraintRange(ConstraintRange* constraints)
{
    constraints->minValue = NULL;
    constraints->maxValue = NULL;
    constraints->increment = NULL;
}

AJ_Status marshalConstraintRange(ConstraintRange* constraints, AJ_Message* reply)
{
    AJ_Status status;
    AJ_Arg constraintRange;

    status = StartComplexOptionalParam(reply, &constraintRange, PROPERTY_CONSTRAINT_RANGE, PROPERTY_CONSTRAINT_RANGE_SIG);
    if (status != AJ_OK) {
        return status;
    }

    status = AddConstraintRange(reply, *constraints->signature, constraints->minValue, constraints->maxValue, constraints->increment);
    if (status != AJ_OK) {
        return status;
    }

    return AJ_MarshalCloseContainer(reply, &constraintRange);
}
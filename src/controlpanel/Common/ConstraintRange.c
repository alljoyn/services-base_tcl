/******************************************************************************
 *    Copyright (c) Open Connectivity Foundation (OCF) and AllJoyn Open
 *    Source Project (AJOSP) Contributors and others.
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
 *     THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 *     WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 *     WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 *     AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 *     DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 *     PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 *     TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 *     PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include <ajtcl/services/Common/ConstraintRange.h>
#include <ajtcl/services/Common/ControlMarshalUtil.h>

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
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

#ifndef CONSTRAINTLIST_H_
#define CONSTRAINTLIST_H_

/** @defgroup ConstraintList Contraint List
 *
 *  @{
 */

#include <alljoyn/controlpanel/Definitions.h>
#include "BaseWidget.h"
#include <alljoyn.h>

/**
 * ConstraintList structure
 */
typedef struct {
    const void* value;                            //!< The constraint value
    const char* const* display;                   //!< The constraint display text
    const char* (*getDisplay)(uint16_t language); //!< Getter for the display text

} ConstraintList;

/**
 * Marshal ConstraintList into given reply message
 * @param widget - pointer to the widget structure
 * @param constraints - the constraints array
 * @param reply - the message to marshal into
 * @param numConstraints - the number of constraints
 * @param signature - signature of value
 * @param language - language requested
 */
AJ_Status marshalConstraintList(BaseWidget* widget, ConstraintList* constraints, AJ_Message* reply, uint16_t numConstraints,
                                const char* signature, uint16_t language);

/** @} */
#endif /* CONTRAINTVALUES_H_ */
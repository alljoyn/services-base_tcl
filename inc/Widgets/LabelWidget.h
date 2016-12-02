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

#ifndef LABELWIDGET_H_
#define LABELWIDGET_H_

/** @defgroup LabelWidget Label Widget
 *
 *  @{
 */

#include <ajtcl/services/Common/BaseWidget.h>

/////////////////////////*     LabelWidget     *//////////////////////////////////////

/**
 * LabelWidget structure - widget to represent a Label
 */
typedef struct LabelWidget {
    BaseWidget base;                                                   //!< Internal BaseWidget

    const char* const* label;                                          //!< The labels of the Widget. Array of labels - one per language
    const char* (*getLabel)(struct LabelWidget* thisWidget, uint16_t); //!< The GetLabel function pointer. Receives a language index and should return the label for that language
} LabelWidget;

/**
 * Initialize the LabelWidget structure
 * @param widget - pointer to LabelWidget structure
 */
void initializeLabelWidget(LabelWidget* widget);

/**
 * Marshal Label of given widget into given reply message
 * @param widget - pointer to widget
 * @param reply - message to marshal into
 * @param language - language requested
 * @return aj_status - success/failure
 */
AJ_Status marshalLabelLabel(LabelWidget* widget, AJ_Message* reply, uint16_t language);

/**
 * Marshal All LabelProperties of given widget into given reply message
 * @param widget - pointer to widget
 * @param reply - message to marshal into
 * @param language - language requested
 * @return aj_status - success/failure
 */
AJ_Status marshalAllLabelProperties(BaseWidget* widget, AJ_Message* reply, uint16_t language);

/** @} */
#endif /* LABELWIDGET_H_ */

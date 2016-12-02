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

#ifndef ACTIONWIDGET_H_
#define ACTIONWIDGET_H_

/** @defgroup ActionWidget Action Widget
 * details Action Widget Struct and Functions that assist in Un/Marshaling
 * Action Widget from/to a message.
 *  @{
 */

#include <alljoyn/controlpanel/Common/BaseWidget.h>

/////////////////////////*     ActionWidget     *//////////////////////////////////////

/**
 * ActionWidget structure - widget to represent an Action(Button)
 */
typedef struct ActionWidget {
    BaseWidget base; //!< Internal BaseWidget
} ActionWidget;

/**
 * Initialize the ActionWidget structure
 * @param widget - pointer to actionWidget structure
 */
void initializeActionWidget(ActionWidget* widget);

/** @} */
#endif /* ACTIONWIDGET_H_ */

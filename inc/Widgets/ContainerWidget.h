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

#ifndef CONTAINERWIDGET_H_
#define CONTAINERWIDGET_H_

/** @defgroup ContainerWidget Container Widget
 *
 *  @{
 */

#include <ajtcl/services/Common/BaseWidget.h>

/////////////////////////*     ContainerWidget     *//////////////////////////////////////

/**
 * ContainerWidget structure - widget to represent a Container containing other widgets
 */
typedef struct {
    BaseWidget base; //!< Internal BaseWidget
} ContainerWidget;

/**
 * Initialize the ContainerWidget structure
 * @param widget - pointer to ContainerWidget structure
 */
void initializeContainerWidget(ContainerWidget* widget);

/** @} */
#endif /* CONTAINERWIDGET_H_ */
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

#ifndef CONTROLPANELINTERFACES_H_
#define CONTROLPANELINTERFACES_H_

#include <ajtcl/alljoyn.h>

/**
 * The Description of the root Interfaces: ControlPanel, NotificationAction and DismissableControlPanel
 */
extern const AJ_InterfaceDescription ControlPanelInterfaces[];
extern const AJ_InterfaceDescription NotificationActionInterfaces[];
extern const AJ_InterfaceDescription DismissableControlPanelInterfaces[];

/**
 * The Description of the PropertyInterface
 */
extern const AJ_InterfaceDescription PropertyInterfaces[];
extern const AJ_InterfaceDescription SecuredPropertyInterfaces[];

/**
 * The Description of the ActionInterface
 */
extern const AJ_InterfaceDescription ActionInterfaces[];
extern const AJ_InterfaceDescription SecuredActionInterfaces[];

/**
 * The Description of the ContainerInterface
 */
extern const AJ_InterfaceDescription ContainerInterfaces[];
extern const AJ_InterfaceDescription SecuredContainerInterfaces[];

/**
 * The Description of the LabelInterface
 */
extern const AJ_InterfaceDescription LabelPropertyInterfaces[];

/**
 * The Description of the DialogInterface
 */
extern const AJ_InterfaceDescription DialogInterfaces[];
extern const AJ_InterfaceDescription SecuredDialogInterfaces[];

/**
 * The Description of the HttpControlInterfaces
 */
extern const AJ_InterfaceDescription HttpControlInterfaces[];

#endif /* CONTROLPANELINTERFACES_H_ */
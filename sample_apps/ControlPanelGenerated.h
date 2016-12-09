/******************************************************************************
 * Copyright (c) 2016 Open Connectivity Foundation (OCF) and AllJoyn Open
 *    Source Project (AJOSP) Contributors and others.
 *
 *    SPDX-License-Identifier: Apache-2.0
 *
 *    All rights reserved. This program and the accompanying materials are
 *    made available under the terms of the Apache License, Version 2.0
 *    which accompanies this distribution, and is available at
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Copyright 2016 Open Connectivity Foundation and Contributors to
 *    AllSeen Alliance. All rights reserved.
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

#ifndef CONTROL_GENERATED_H_
#define CONTROL_GENERATED_H_

#include <alljoyn.h>
#include <alljoyn/controlpanel/Widgets/ActionWidget.h>
#include <alljoyn/controlpanel/Widgets/PropertyWidget.h>
#include <alljoyn/controlpanel/Widgets/ContainerWidget.h>
#include <alljoyn/controlpanel/Widgets/LabelWidget.h>
#include <alljoyn/controlpanel/Widgets/DialogWidget.h>
#include <alljoyn/controlpanel/Common/HttpControl.h>
#include <alljoyn/services_common/ServicesCommon.h>

/**
 * Defines and objectPaths
 */

#define GET_WIDGET_VALUE_CASES \
case EN_MYDEVICE_ROOTCONTAINER_GET_VALUE: \
case DE_AT_MYDEVICE_ROOTCONTAINER_GET_VALUE: \
case EN_MYDEVICE_CURRENTTEMP_GET_VALUE: \
case DE_AT_MYDEVICE_CURRENTTEMP_GET_VALUE: \
case EN_MYDEVICE_HEATPROPERTY_GET_VALUE: \
case DE_AT_MYDEVICE_HEATPROPERTY_GET_VALUE: \
case EN_MYDEVICE_OVENACTION_GET_VALUE: \
case DE_AT_MYDEVICE_OVENACTION_GET_VALUE: \
case EN_MYDEVICE_LIGHTACTION_GET_VALUE: \
case DE_AT_MYDEVICE_LIGHTACTION_GET_VALUE: \
case EN_MYDEVICE_LIGHTCONFIRM_GET_VALUE: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_GET_VALUE: \
case EN_MYDEVICE_AREYOUSURE_GET_VALUE: \
case DE_AT_MYDEVICE_AREYOUSURE_GET_VALUE: \


#define GET_WIDGET_ALL_VALUE_CASES \
case EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES: \
case EN_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES: \
case EN_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES: \
case EN_MYDEVICE_OVENACTION_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_OVENACTION_GET_ALL_VALUES: \
case EN_MYDEVICE_LIGHTACTION_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_LIGHTACTION_GET_ALL_VALUES: \
case EN_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES: \
case EN_MYDEVICE_AREYOUSURE_GET_ALL_VALUES: \
case DE_AT_MYDEVICE_AREYOUSURE_GET_ALL_VALUES: \


#define GET_ROOT_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_VALUE: \
case MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_VALUE: \


#define GET_ROOT_ALL_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_ALL_VALUES: \
case MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_ALL_VALUES: \


#define SET_VALUE_CASES \
case MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_SET_VALUE: \
case EN_MYDEVICE_ROOTCONTAINER_SET_VALUE: \
case DE_AT_MYDEVICE_ROOTCONTAINER_SET_VALUE: \
case EN_MYDEVICE_CURRENTTEMP_SET_VALUE: \
case DE_AT_MYDEVICE_CURRENTTEMP_SET_VALUE: \
case EN_MYDEVICE_HEATPROPERTY_SET_VALUE: \
case DE_AT_MYDEVICE_HEATPROPERTY_SET_VALUE: \
case EN_MYDEVICE_OVENACTION_SET_VALUE: \
case DE_AT_MYDEVICE_OVENACTION_SET_VALUE: \
case EN_MYDEVICE_LIGHTACTION_SET_VALUE: \
case DE_AT_MYDEVICE_LIGHTACTION_SET_VALUE: \
case EN_MYDEVICE_LIGHTCONFIRM_SET_VALUE: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_SET_VALUE: \
case MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_SET_VALUE: \
case EN_MYDEVICE_AREYOUSURE_SET_VALUE: \
case DE_AT_MYDEVICE_AREYOUSURE_SET_VALUE: \


#define ACTION_CASES \
case EN_MYDEVICE_OVENACTION_EXEC: \
case DE_AT_MYDEVICE_OVENACTION_EXEC: \
case EN_MYDEVICE_LIGHTACTION_EXEC: \
case DE_AT_MYDEVICE_LIGHTACTION_EXEC: \
case EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1: \
case EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2: \
case EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2: \
case DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3: \
case EN_MYDEVICE_AREYOUSURE_EXEC_ACTION1: \
case EN_MYDEVICE_AREYOUSURE_EXEC_ACTION2: \
case EN_MYDEVICE_AREYOUSURE_EXEC_ACTION3: \
case DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION1: \
case DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION2: \
case DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION3: \


#define GET_URL_CASES \


#define AJCPS_CONTROLLEE_GENERATED_OBJECTS \
    {  MyDeviceRootContainerObjectPath, ControlPanelInterfaces, AJ_OBJ_FLAG_HIDDEN | AJ_OBJ_FLAG_DISABLED | AJ_OBJ_FLAG_ANNOUNCED  }, \
    {  enMyDeviceRootContainerObjectPath, ContainerInterfaces  }, \
    {  de_ATMyDeviceRootContainerObjectPath, ContainerInterfaces  }, \
    {  enMyDeviceCurrentTempObjectPath, LabelPropertyInterfaces  }, \
    {  de_ATMyDeviceCurrentTempObjectPath, LabelPropertyInterfaces  }, \
    {  enMyDeviceHeatPropertyObjectPath, PropertyInterfaces  }, \
    {  de_ATMyDeviceHeatPropertyObjectPath, PropertyInterfaces  }, \
    {  enMyDeviceOvenActionObjectPath, ActionInterfaces  }, \
    {  de_ATMyDeviceOvenActionObjectPath, ActionInterfaces  }, \
    {  enMyDeviceLightActionObjectPath, ActionInterfaces  }, \
    {  de_ATMyDeviceLightActionObjectPath, ActionInterfaces  }, \
    {  enMyDeviceLightConfirmObjectPath, DialogInterfaces  }, \
    {  de_ATMyDeviceLightConfirmObjectPath, DialogInterfaces  }, \
    {  MyDeviceAreYouSureObjectPath, NotificationActionInterfaces  }, \
    {  enMyDeviceAreYouSureObjectPath, DialogInterfaces  }, \
    {  de_ATMyDeviceAreYouSureObjectPath, DialogInterfaces  }, \


#define AJCPS_CONTROLLEE_GENERATED_OBJECTS_COUNT               16

#define MAX_NUM_LANGUAGES                                      2

#define MYDEVICE_MYLANGUAGES_EN 0
#define MYDEVICE_MYLANGUAGES_DE_AT 1

#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_GET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_SET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 0, 0, AJ_PROP_GET_ALL)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 0, 1, 0)

#define EN_MYDEVICE_ROOTCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_GET)
#define EN_MYDEVICE_ROOTCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_SET)
#define EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_ROOTCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 0)
#define EN_MYDEVICE_ROOTCONTAINER_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 1)
#define EN_MYDEVICE_ROOTCONTAINER_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 2)
#define EN_MYDEVICE_ROOTCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 1, 1, 3)

#define DE_AT_MYDEVICE_ROOTCONTAINER_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_ROOTCONTAINER_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_ROOTCONTAINER_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 0)
#define DE_AT_MYDEVICE_ROOTCONTAINER_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 1)
#define DE_AT_MYDEVICE_ROOTCONTAINER_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 2)
#define DE_AT_MYDEVICE_ROOTCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 2, 1, 3)

#define EN_MYDEVICE_CURRENTTEMP_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_GET)
#define EN_MYDEVICE_CURRENTTEMP_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_SET)
#define EN_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_CURRENTTEMP_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 0)
#define EN_MYDEVICE_CURRENTTEMP_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 1)
#define EN_MYDEVICE_CURRENTTEMP_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 2)
#define EN_MYDEVICE_CURRENTTEMP_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 3)
#define EN_MYDEVICE_CURRENTTEMP_LABEL_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 3, 1, 4)

#define DE_AT_MYDEVICE_CURRENTTEMP_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_CURRENTTEMP_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_CURRENTTEMP_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 0)
#define DE_AT_MYDEVICE_CURRENTTEMP_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 1)
#define DE_AT_MYDEVICE_CURRENTTEMP_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 2)
#define DE_AT_MYDEVICE_CURRENTTEMP_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 3)
#define DE_AT_MYDEVICE_CURRENTTEMP_LABEL_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 4, 1, 4)

#define EN_MYDEVICE_HEATPROPERTY_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_GET)
#define EN_MYDEVICE_HEATPROPERTY_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_SET)
#define EN_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_HEATPROPERTY_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 0)
#define EN_MYDEVICE_HEATPROPERTY_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 1)
#define EN_MYDEVICE_HEATPROPERTY_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 2)
#define EN_MYDEVICE_HEATPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 3)
#define EN_MYDEVICE_HEATPROPERTY_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 4)
#define EN_MYDEVICE_HEATPROPERTY_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 5, 1, 5)

#define DE_AT_MYDEVICE_HEATPROPERTY_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_HEATPROPERTY_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_HEATPROPERTY_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 0)
#define DE_AT_MYDEVICE_HEATPROPERTY_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 1)
#define DE_AT_MYDEVICE_HEATPROPERTY_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 2)
#define DE_AT_MYDEVICE_HEATPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 3)
#define DE_AT_MYDEVICE_HEATPROPERTY_VALUE_PROPERTY             AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 4)
#define DE_AT_MYDEVICE_HEATPROPERTY_SIGNAL_VALUE_CHANGED       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 6, 1, 5)

#define EN_MYDEVICE_OVENACTION_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_GET)
#define EN_MYDEVICE_OVENACTION_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_SET)
#define EN_MYDEVICE_OVENACTION_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_OVENACTION_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 0)
#define EN_MYDEVICE_OVENACTION_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 1)
#define EN_MYDEVICE_OVENACTION_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 2)
#define EN_MYDEVICE_OVENACTION_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 3)
#define EN_MYDEVICE_OVENACTION_EXEC                       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 7, 1, 4)

#define DE_AT_MYDEVICE_OVENACTION_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_OVENACTION_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_OVENACTION_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_OVENACTION_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 0)
#define DE_AT_MYDEVICE_OVENACTION_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 1)
#define DE_AT_MYDEVICE_OVENACTION_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 2)
#define DE_AT_MYDEVICE_OVENACTION_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 3)
#define DE_AT_MYDEVICE_OVENACTION_EXEC                       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 8, 1, 4)

#define EN_MYDEVICE_LIGHTACTION_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_GET)
#define EN_MYDEVICE_LIGHTACTION_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_SET)
#define EN_MYDEVICE_LIGHTACTION_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_LIGHTACTION_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 0)
#define EN_MYDEVICE_LIGHTACTION_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 1)
#define EN_MYDEVICE_LIGHTACTION_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 2)
#define EN_MYDEVICE_LIGHTACTION_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 3)
#define EN_MYDEVICE_LIGHTACTION_EXEC                       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 9, 1, 4)

#define DE_AT_MYDEVICE_LIGHTACTION_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 10, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_LIGHTACTION_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 10, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_LIGHTACTION_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 10, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_LIGHTACTION_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 10, 1, 0)
#define DE_AT_MYDEVICE_LIGHTACTION_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 10, 1, 1)
#define DE_AT_MYDEVICE_LIGHTACTION_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 10, 1, 2)
#define DE_AT_MYDEVICE_LIGHTACTION_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 10, 1, 3)
#define DE_AT_MYDEVICE_LIGHTACTION_EXEC                       AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 10, 1, 4)

#define EN_MYDEVICE_LIGHTCONFIRM_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 0, AJ_PROP_GET)
#define EN_MYDEVICE_LIGHTCONFIRM_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 0, AJ_PROP_SET)
#define EN_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_LIGHTCONFIRM_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 0)
#define EN_MYDEVICE_LIGHTCONFIRM_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 1)
#define EN_MYDEVICE_LIGHTCONFIRM_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 2)
#define EN_MYDEVICE_LIGHTCONFIRM_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 3)
#define EN_MYDEVICE_LIGHTCONFIRM_MESSAGE_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 4)
#define EN_MYDEVICE_LIGHTCONFIRM_NUM_ACTIONS_PROPERTY       AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 5)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 6)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 7)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 11, 1, 8)

#define DE_AT_MYDEVICE_LIGHTCONFIRM_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 0)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 1)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 2)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 3)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_MESSAGE_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 4)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_NUM_ACTIONS_PROPERTY       AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 5)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 6)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 7)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 12, 1, 8)

#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 13, 0, AJ_PROP_GET)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 13, 0, AJ_PROP_SET)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 13, 0, AJ_PROP_GET_ALL)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 13, 1, 0)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_SIGNAL_DISMISS             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 13, 1, 1)

#define EN_MYDEVICE_AREYOUSURE_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 0, AJ_PROP_GET)
#define EN_MYDEVICE_AREYOUSURE_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 0, AJ_PROP_SET)
#define EN_MYDEVICE_AREYOUSURE_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_AREYOUSURE_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 0)
#define EN_MYDEVICE_AREYOUSURE_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 1)
#define EN_MYDEVICE_AREYOUSURE_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 2)
#define EN_MYDEVICE_AREYOUSURE_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 3)
#define EN_MYDEVICE_AREYOUSURE_MESSAGE_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 4)
#define EN_MYDEVICE_AREYOUSURE_NUM_ACTIONS_PROPERTY       AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 5)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION1               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 6)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION2               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 7)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION3               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 14, 1, 8)

#define DE_AT_MYDEVICE_AREYOUSURE_GET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_AREYOUSURE_SET_VALUE                  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_AREYOUSURE_GET_ALL_VALUES             AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_AREYOUSURE_VERSION_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 0)
#define DE_AT_MYDEVICE_AREYOUSURE_STATES_PROPERTY            AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 1)
#define DE_AT_MYDEVICE_AREYOUSURE_OPTPARAMS_PROPERTY         AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 2)
#define DE_AT_MYDEVICE_AREYOUSURE_SIGNAL_PROPERTIES_CHANGED  AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 3)
#define DE_AT_MYDEVICE_AREYOUSURE_MESSAGE_PROPERTY           AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 4)
#define DE_AT_MYDEVICE_AREYOUSURE_NUM_ACTIONS_PROPERTY       AJ_ENCODE_PROPERTY_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 5)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION1               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 6)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION2               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 7)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION3               AJ_ENCODE_MESSAGE_ID(AJCPS_OBJECT_LIST_INDEX, 15, 1, 8)



extern const char MyDeviceRootContainerObjectPath[];
extern const char enMyDeviceRootContainerObjectPath[];
extern const char de_ATMyDeviceRootContainerObjectPath[];
extern const char enMyDeviceCurrentTempObjectPath[];
extern const char de_ATMyDeviceCurrentTempObjectPath[];
extern const char enMyDeviceHeatPropertyObjectPath[];
extern const char de_ATMyDeviceHeatPropertyObjectPath[];
extern const char enMyDeviceOvenActionObjectPath[];
extern const char de_ATMyDeviceOvenActionObjectPath[];
extern const char enMyDeviceLightActionObjectPath[];
extern const char de_ATMyDeviceLightActionObjectPath[];
extern const char enMyDeviceLightConfirmObjectPath[];
extern const char de_ATMyDeviceLightConfirmObjectPath[];
extern const char MyDeviceAreYouSureObjectPath[];
extern const char enMyDeviceAreYouSureObjectPath[];
extern const char de_ATMyDeviceAreYouSureObjectPath[];


extern ContainerWidget MyDeviceRootContainer;
extern LabelWidget MyDeviceCurrentTemp;
extern PropertyWidget MyDeviceHeatProperty;
extern ActionWidget MyDeviceOvenAction;
extern ActionWidget MyDeviceLightAction;
extern DialogWidget MyDeviceLightConfirm;
extern DialogWidget MyDeviceAreYouSure;


typedef struct {
    const char* sender;
    uint16_t numSignals;
    int32_t signals[MAX_NUM_LANGUAGES];
} SetValueContext;

typedef struct {
    uint8_t signalType;
    int32_t signalId;
} Signal;

typedef struct {
    uint16_t numSignals;
    Signal signals[MAX_NUM_LANGUAGES * 2];
} ExecuteActionContext;
/**
 *
 * @return
 */
void WidgetsInit();

/**
 * Set Value of a property.
 * @param replyMsg - reply message
 * @param propId - id of property being changed
 * @param context - setvaluecontext. can be used to send signals
 * @return status
 */
AJ_Status SetValueProperty(AJ_Message* replyMsg, uint32_t propId, void* context);

/**
 * Execute Action
 * @param msg - the msg for the response
 * @param msgId - the Action being executed
 * @param context - ExecuteActionContext used to send signals as a result of action
 * @return status
 */
AJ_Status ExecuteAction(AJ_Message* msg, uint32_t msgId, ExecuteActionContext* context);


/* Defines and functions for Tester App */
typedef struct {
    uint32_t msgId;
    uint16_t numParams;
    uint16_t param[3];
} CPSTest;

#define NUMBER_OF_TESTS //NUM_TESTS_GO_HERE

#define ALL_REPLY_CASES                //ALL_REPLIES_GO_HERE

void TestsInit(CPSTest* testsToRun);

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language);
void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty);
uint8_t IdentifyRootMsgOrPropId(uint32_t identifier);
AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus);

#endif /* CONTROL_GENERATED_H_ */
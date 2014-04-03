/******************************************************************************
 * Copyright (c) 2013 - 2014, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
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
#define NUM_PRECEDING_OBJECTS NUM_PRE_CONTROLPANEL_OBJECTS

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


#define CONTROLPANELAPPOBJECTS     {  MyDeviceRootContainerObjectPath, ControlPanelInterfaces  }, \
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


#define CONTROLPANELANNOUNCEOBJECTS     {  MyDeviceRootContainerObjectPath, ControlPanelInterfaces  }, \


#define MAX_NUM_LANGUAGES 2

#define NUM_CONTROLPANEL_OBJECTS 16

#define MYDEVICE_MYLANGUAGES_EN 0
#define MYDEVICE_MYLANGUAGES_DE_AT 1

#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_VALUE                  AJ_PRX_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_SET_VALUE                  AJ_PRX_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(0 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define MYDEVICE_ROOT_CONTROLPANEL_ROOTCONTAINER_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(0 + NUM_PRECEDING_OBJECTS, 1, 0)

#define EN_MYDEVICE_ROOTCONTAINER_GET_VALUE                  AJ_PRX_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_ROOTCONTAINER_SET_VALUE                  AJ_PRX_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_ROOTCONTAINER_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(1 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_ROOTCONTAINER_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(1 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_ROOTCONTAINER_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(1 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_ROOTCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(1 + NUM_PRECEDING_OBJECTS, 1, 3)

#define DE_AT_MYDEVICE_ROOTCONTAINER_GET_VALUE                  AJ_PRX_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_ROOTCONTAINER_SET_VALUE                  AJ_PRX_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_ROOTCONTAINER_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_ROOTCONTAINER_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_ROOTCONTAINER_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(2 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_ROOTCONTAINER_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(2 + NUM_PRECEDING_OBJECTS, 1, 3)

#define EN_MYDEVICE_CURRENTTEMP_GET_VALUE                  AJ_PRX_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_CURRENTTEMP_SET_VALUE                  AJ_PRX_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_CURRENTTEMP_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_CURRENTTEMP_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_CURRENTTEMP_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_CURRENTTEMP_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(3 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_CURRENTTEMP_LABEL_PROPERTY             AJ_PRX_PROPERTY_ID(3 + NUM_PRECEDING_OBJECTS, 1, 4)

#define DE_AT_MYDEVICE_CURRENTTEMP_GET_VALUE                  AJ_PRX_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_CURRENTTEMP_SET_VALUE                  AJ_PRX_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_CURRENTTEMP_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_CURRENTTEMP_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_CURRENTTEMP_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_CURRENTTEMP_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(4 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_CURRENTTEMP_LABEL_PROPERTY             AJ_PRX_PROPERTY_ID(4 + NUM_PRECEDING_OBJECTS, 1, 4)

#define EN_MYDEVICE_HEATPROPERTY_GET_VALUE                  AJ_PRX_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_HEATPROPERTY_SET_VALUE                  AJ_PRX_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_HEATPROPERTY_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_HEATPROPERTY_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_HEATPROPERTY_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_HEATPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_HEATPROPERTY_VALUE_PROPERTY             AJ_PRX_PROPERTY_ID(5 + NUM_PRECEDING_OBJECTS, 1, 4)
#define EN_MYDEVICE_HEATPROPERTY_SIGNAL_VALUE_CHANGED       AJ_PRX_MESSAGE_ID(5 + NUM_PRECEDING_OBJECTS, 1, 5)

#define DE_AT_MYDEVICE_HEATPROPERTY_GET_VALUE                  AJ_PRX_MESSAGE_ID(6 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_HEATPROPERTY_SET_VALUE                  AJ_PRX_MESSAGE_ID(6 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(6 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_HEATPROPERTY_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(6 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_HEATPROPERTY_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(6 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_HEATPROPERTY_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(6 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_HEATPROPERTY_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(6 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_HEATPROPERTY_VALUE_PROPERTY             AJ_PRX_PROPERTY_ID(6 + NUM_PRECEDING_OBJECTS, 1, 4)
#define DE_AT_MYDEVICE_HEATPROPERTY_SIGNAL_VALUE_CHANGED       AJ_PRX_MESSAGE_ID(6 + NUM_PRECEDING_OBJECTS, 1, 5)

#define EN_MYDEVICE_OVENACTION_GET_VALUE                  AJ_PRX_MESSAGE_ID(7 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_OVENACTION_SET_VALUE                  AJ_PRX_MESSAGE_ID(7 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_OVENACTION_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(7 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_OVENACTION_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(7 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_OVENACTION_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(7 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_OVENACTION_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(7 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_OVENACTION_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(7 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_OVENACTION_EXEC                       AJ_PRX_MESSAGE_ID(7 + NUM_PRECEDING_OBJECTS, 1, 4)

#define DE_AT_MYDEVICE_OVENACTION_GET_VALUE                  AJ_PRX_MESSAGE_ID(8 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_OVENACTION_SET_VALUE                  AJ_PRX_MESSAGE_ID(8 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_OVENACTION_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(8 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_OVENACTION_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(8 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_OVENACTION_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(8 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_OVENACTION_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(8 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_OVENACTION_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(8 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_OVENACTION_EXEC                       AJ_PRX_MESSAGE_ID(8 + NUM_PRECEDING_OBJECTS, 1, 4)

#define EN_MYDEVICE_LIGHTACTION_GET_VALUE                  AJ_PRX_MESSAGE_ID(9 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_LIGHTACTION_SET_VALUE                  AJ_PRX_MESSAGE_ID(9 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_LIGHTACTION_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(9 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_LIGHTACTION_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(9 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_LIGHTACTION_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(9 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_LIGHTACTION_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(9 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_LIGHTACTION_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(9 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_LIGHTACTION_EXEC                       AJ_PRX_MESSAGE_ID(9 + NUM_PRECEDING_OBJECTS, 1, 4)

#define DE_AT_MYDEVICE_LIGHTACTION_GET_VALUE                  AJ_PRX_MESSAGE_ID(10 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_LIGHTACTION_SET_VALUE                  AJ_PRX_MESSAGE_ID(10 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_LIGHTACTION_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(10 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_LIGHTACTION_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(10 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_LIGHTACTION_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(10 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_LIGHTACTION_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(10 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_LIGHTACTION_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(10 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_LIGHTACTION_EXEC                       AJ_PRX_MESSAGE_ID(10 + NUM_PRECEDING_OBJECTS, 1, 4)

#define EN_MYDEVICE_LIGHTCONFIRM_GET_VALUE                  AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_LIGHTCONFIRM_SET_VALUE                  AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_LIGHTCONFIRM_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(11 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_LIGHTCONFIRM_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(11 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_LIGHTCONFIRM_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(11 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_LIGHTCONFIRM_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_LIGHTCONFIRM_MESSAGE_PROPERTY           AJ_PRX_PROPERTY_ID(11 + NUM_PRECEDING_OBJECTS, 1, 4)
#define EN_MYDEVICE_LIGHTCONFIRM_NUM_ACTIONS_PROPERTY       AJ_PRX_PROPERTY_ID(11 + NUM_PRECEDING_OBJECTS, 1, 5)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1               AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 1, 6)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2               AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 1, 7)
#define EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3               AJ_PRX_MESSAGE_ID(11 + NUM_PRECEDING_OBJECTS, 1, 8)

#define DE_AT_MYDEVICE_LIGHTCONFIRM_GET_VALUE                  AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_SET_VALUE                  AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(12 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(12 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(12 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_MESSAGE_PROPERTY           AJ_PRX_PROPERTY_ID(12 + NUM_PRECEDING_OBJECTS, 1, 4)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_NUM_ACTIONS_PROPERTY       AJ_PRX_PROPERTY_ID(12 + NUM_PRECEDING_OBJECTS, 1, 5)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1               AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 1, 6)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2               AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 1, 7)
#define DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3               AJ_PRX_MESSAGE_ID(12 + NUM_PRECEDING_OBJECTS, 1, 8)

#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_VALUE                  AJ_PRX_MESSAGE_ID(13 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_SET_VALUE                  AJ_PRX_MESSAGE_ID(13 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(13 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(13 + NUM_PRECEDING_OBJECTS, 1, 0)
#define MYDEVICE_NOTIFICATION_ACTION_AREYOUSURE_SIGNAL_DISMISS             AJ_PRX_MESSAGE_ID(13 + NUM_PRECEDING_OBJECTS, 1, 1)

#define EN_MYDEVICE_AREYOUSURE_GET_VALUE                  AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define EN_MYDEVICE_AREYOUSURE_SET_VALUE                  AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define EN_MYDEVICE_AREYOUSURE_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define EN_MYDEVICE_AREYOUSURE_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(14 + NUM_PRECEDING_OBJECTS, 1, 0)
#define EN_MYDEVICE_AREYOUSURE_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(14 + NUM_PRECEDING_OBJECTS, 1, 1)
#define EN_MYDEVICE_AREYOUSURE_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(14 + NUM_PRECEDING_OBJECTS, 1, 2)
#define EN_MYDEVICE_AREYOUSURE_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 1, 3)
#define EN_MYDEVICE_AREYOUSURE_MESSAGE_PROPERTY           AJ_PRX_PROPERTY_ID(14 + NUM_PRECEDING_OBJECTS, 1, 4)
#define EN_MYDEVICE_AREYOUSURE_NUM_ACTIONS_PROPERTY       AJ_PRX_PROPERTY_ID(14 + NUM_PRECEDING_OBJECTS, 1, 5)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION1               AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 1, 6)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION2               AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 1, 7)
#define EN_MYDEVICE_AREYOUSURE_EXEC_ACTION3               AJ_PRX_MESSAGE_ID(14 + NUM_PRECEDING_OBJECTS, 1, 8)

#define DE_AT_MYDEVICE_AREYOUSURE_GET_VALUE                  AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET)
#define DE_AT_MYDEVICE_AREYOUSURE_SET_VALUE                  AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_SET)
#define DE_AT_MYDEVICE_AREYOUSURE_GET_ALL_VALUES             AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 0, AJ_PROP_GET_ALL)
#define DE_AT_MYDEVICE_AREYOUSURE_VERSION_PROPERTY           AJ_PRX_PROPERTY_ID(15 + NUM_PRECEDING_OBJECTS, 1, 0)
#define DE_AT_MYDEVICE_AREYOUSURE_STATES_PROPERTY            AJ_PRX_PROPERTY_ID(15 + NUM_PRECEDING_OBJECTS, 1, 1)
#define DE_AT_MYDEVICE_AREYOUSURE_OPTPARAMS_PROPERTY         AJ_PRX_PROPERTY_ID(15 + NUM_PRECEDING_OBJECTS, 1, 2)
#define DE_AT_MYDEVICE_AREYOUSURE_SIGNAL_PROPERTIES_CHANGED  AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 1, 3)
#define DE_AT_MYDEVICE_AREYOUSURE_MESSAGE_PROPERTY           AJ_PRX_PROPERTY_ID(15 + NUM_PRECEDING_OBJECTS, 1, 4)
#define DE_AT_MYDEVICE_AREYOUSURE_NUM_ACTIONS_PROPERTY       AJ_PRX_PROPERTY_ID(15 + NUM_PRECEDING_OBJECTS, 1, 5)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION1               AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 1, 6)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION2               AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 1, 7)
#define DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION3               AJ_PRX_MESSAGE_ID(15 + NUM_PRECEDING_OBJECTS, 1, 8)



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


//WIDGETS_DECL_GO_HERE

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

#define NUMBER_OF_TESTS 30

#define ALL_REPLY_CASES                case AJ_REPLY_ID(EN_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_ROOTCONTAINER_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_CURRENTTEMP_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_HEATPROPERTY_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_OVENACTION_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_OVENACTION_EXEC): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_OVENACTION_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_OVENACTION_EXEC): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTACTION_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTACTION_EXEC): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTACTION_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTACTION_EXEC): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2): \
case AJ_REPLY_ID(EN_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTCONFIRM_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION1): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION2): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_LIGHTCONFIRM_EXEC_ACTION3): \
case AJ_REPLY_ID(EN_MYDEVICE_AREYOUSURE_GET_ALL_VALUES): \
case AJ_REPLY_ID(EN_MYDEVICE_AREYOUSURE_EXEC_ACTION1): \
case AJ_REPLY_ID(EN_MYDEVICE_AREYOUSURE_EXEC_ACTION2): \
case AJ_REPLY_ID(EN_MYDEVICE_AREYOUSURE_EXEC_ACTION3): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_AREYOUSURE_GET_ALL_VALUES): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION1): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION2): \
case AJ_REPLY_ID(DE_AT_MYDEVICE_AREYOUSURE_EXEC_ACTION3): \


void TestsInit(CPSTest* testsToRun);

void* IdentifyMsgOrPropId(uint32_t identifier, uint16_t* widgetType, uint16_t* propType, uint16_t* language);
void* IdentifyMsgOrPropIdForSignal(uint32_t identifier, uint8_t* isProperty);
uint8_t IdentifyRootMsgOrPropId(uint32_t identifier);
AJSVC_ServiceStatus GeneratedMessageProcessor(AJ_BusAttachment* bus, AJ_Message* msg, AJ_Status* msgStatus);

#endif /* CONTROL_GENERATED_H_ */

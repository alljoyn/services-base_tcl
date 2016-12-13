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

#include <alljoyn.h>
#include <aj_config.h>
#include <aj_creds.h>
#include <aj_nvram.h>
#include <aj_link_timeout.h>

#include "PropertyStoreOEMProvisioning.h"
#ifdef ONBOARDING_SERVICE
    #include <alljoyn/onboarding/OnboardingManager.h>
#endif
#ifdef CONTROLPANEL_SERVICE
    #include "ControlPanelGenerated.h"
#endif

#include <alljoyn/services_common/PropertyStore.h>
#include <alljoyn/services_common/ServicesCommon.h>
#include <alljoyn/services_common/ServicesHandlers.h>
#include "AppHandlers.h"
#ifdef EVENTS_AND_ACTIONS
#include "EventsAndActionsSample.h"
#endif

#ifndef NDEBUG
#ifndef ER_DEBUG_AJSVCAPP
#define ER_DEBUG_AJSVCAPP 0
#endif
AJ_EXPORT uint8_t dbgAJSVCAPP = ER_DEBUG_AJSVCAPP;
#endif

/**
 * Application wide globals
 */

#define ROUTING_NODE_NAME "org.alljoyn.BusNode"
static uint8_t isBusConnected = FALSE;

/*
 * Define timeout/pause values. Values are in milli seconds.
 * The following may be tuned according to platform requirements such as battery usage.
 */
#define AJAPP_BUS_LINK_TIMEOUT    60
#define AJAPP_CONNECT_TIMEOUT     (1000 * 60 * 10) // Override AJ_CONNECT_TIMEOUT to wait longer for a successful connection to a Routing Node
#define AJAPP_CONNECT_PAUSE       (1000 * 2)       // Override AJ_CONNECT_PAUSE to be more responsive
#define AJAPP_SLEEP_TIME          (1000 * 2)       // A little pause to let things settle
#define AJAPP_UNMARSHAL_TIMEOUT   (1000 * 1)       // Override AJ_UNMARSHAL_TIMEOUT to be more responsive

#define AJAPP_MAX_INIT_ATTEMPTS   3 // Maximum number of attempts to initialize the services

static AJ_BusAttachment busAttachment;
#define AJ_ABOUT_SERVICE_PORT     900

/**
 * Application wide callbacks
 */

static uint32_t MyBusAuthPwdCB(uint8_t* buf, uint32_t bufLen)
{
    const char* myRoutingNodePwd = "000000";
    strncpy((char*)buf, myRoutingNodePwd, bufLen);
    return (uint32_t)strlen(myRoutingNodePwd);
}

static uint32_t PasswordCallback(uint8_t* buffer, uint32_t bufLen)
{
    AJ_Status status = AJ_OK;
    const char* hexPassword = AJSVC_PropertyStore_GetValue(AJSVC_PROPERTY_STORE_PASSCODE);
    size_t hexPasswordLen;
    uint32_t len = 0;

    if (hexPassword == NULL) {
        AJ_AlwaysPrintf(("Password is NULL!\n"));
        return len;
    }
    AJ_AlwaysPrintf(("Configured password=%s\n", hexPassword));
    hexPasswordLen = strlen(hexPassword);
    len = hexPasswordLen / 2;
    status = AJ_HexToRaw(hexPassword, hexPasswordLen, buffer, bufLen);
    if (status == AJ_ERR_RESOURCES) {
        len = 0;
    }

    return len;
}

/**
 * Services Provisioning
 */

const char* deviceManufactureName = "QCA";
const char* deviceProductName = "AC";

static const char DEFAULT_LANGUAGE[] = "en";
static const char* DEFAULT_LANGUAGES[] = { DEFAULT_LANGUAGE };
static const char* SUPPORTED_LANGUAGES[] = { DEFAULT_LANGUAGE, NULL };
const char* const* propertyStoreDefaultLanguages = SUPPORTED_LANGUAGES;

/**
 * property array of default values
 */
static const char* DEFAULT_PASSCODES[] = { "303030303030" }; // HEX encoded { '0', '0', '0', '0', '0', '0' }
static const char* DEFAULT_APP_NAMES[] = { "Controllee" };
static const char* DEFAULT_DESCRIPTIONS[] = { "AC IOE device" };
static const char* DEFAULT_MANUFACTURERS[] = { "Company A(EN)" };
static const char* DEFAULT_DEVICE_MODELS[] = { "0.0.1" };
static const char* DEFAULT_DATE_OF_MANUFACTURES[] = { "2014-05-01" };
static const char* DEFAULT_SOFTWARE_VERSIONS[] = { "0.0.1" };
static const char* DEFAULT_HARDWARE_VERSIONS[] = { "0.0.1" };
static const char* DEFAULT_SUPPORT_URLS[] = { "http://www.allseenalliance.org" };

const char** propertyStoreDefaultValues[AJSVC_PROPERTY_STORE_NUMBER_OF_KEYS] =
{
// "Default Values per language",    "Key Name"
    NULL,                           /*DeviceId*/
    NULL,                           /*AppId*/
    NULL,                           /*DeviceName*/
    DEFAULT_LANGUAGES,              /*DefaultLanguage*/
    DEFAULT_PASSCODES,              /*Passcode*/
    NULL,                           /*RealmName*/
// Add other runtime or configurable keys above this line
    DEFAULT_APP_NAMES,              /*AppName*/
    DEFAULT_DESCRIPTIONS,           /*Description*/
    DEFAULT_MANUFACTURERS,          /*Manufacturer*/
    DEFAULT_DEVICE_MODELS,          /*ModelNumber*/
    DEFAULT_DATE_OF_MANUFACTURES,   /*DateOfManufacture*/
    DEFAULT_SOFTWARE_VERSIONS,      /*SoftwareVersion*/
    NULL,                           /*AJSoftwareVersion*/
    NULL,                           /*MaxLength*/
// Add other mandatory about keys above this line
    DEFAULT_HARDWARE_VERSIONS,      /*HardwareVersion*/
    DEFAULT_SUPPORT_URLS,           /*SupportUrl*/
// Add other optional about keys above this line
};

/**
 * properties array of runtime values' buffers
 */
static char machineIdVar[MACHINE_ID_LENGTH + 1] = { 0 };
static char* machineIdVars[] = { machineIdVar };
static char deviceNameVar[DEVICE_NAME_VALUE_LENGTH + 1] = { 0 };
static char* deviceNameVars[] = { deviceNameVar };
#ifdef CONFIG_SERVICE
static char defaultLanguageVar[LANG_VALUE_LENGTH + 1] = { 0 };
static char* defaultLanguageVars[] = { defaultLanguageVar };
static char passcodeVar[PASSWORD_VALUE_LENGTH + 1] = { 0 };
static char* passcodeVars[] = { passcodeVar };
static char realmNameVar[KEY_VALUE_LENGTH + 1] = { 0 };
static char* realmNameVars[] = { realmNameVar };
#endif

PropertyStoreConfigEntry propertyStoreRuntimeValues[AJSVC_PROPERTY_STORE_NUMBER_OF_RUNTIME_KEYS] =
{
//  {"Buffers for Values per language", "Buffer Size"},                  "Key Name"
    { machineIdVars,             MACHINE_ID_LENGTH + 1 },               /*DeviceId*/
    { machineIdVars,             MACHINE_ID_LENGTH + 1 },               /*AppId*/
    { deviceNameVars,            DEVICE_NAME_VALUE_LENGTH + 1 },        /*DeviceName*/
#ifdef CONFIG_SERVICE
    { defaultLanguageVars,       LANG_VALUE_LENGTH + 1 },               /*DefaultLanguage*/
    { passcodeVars,              PASSWORD_VALUE_LENGTH + 1 },           /*Passcode*/
    { realmNameVars,             KEY_VALUE_LENGTH + 1 },                /*RealmName*/
#endif
};

const char* aboutIconMimetype = { "image/png" };
const uint8_t aboutIconContent[] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x28, 0x08, 0x06, 0x00, 0x00, 0x00, 0x8c, 0xfe, 0xb8, 0x6d, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x02, 0x40, 0xc0, 0x7d, 0xc5, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x17, 0x12, 0x00, 0x00, 0x17, 0x12, 0x01, 0x67, 0x9f, 0xd2, 0x52, 0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, 0x4f, 0x66, 0x66, 0x69, 0x63, 0x65, 0x7f, 0xed, 0x35, 0x71, 0x00, 0x00, 0x04, 0x51, 0x49, 0x44, 0x41, 0x54, 0x58, 0xc3, 0xbd, 0x58, 0x3d, 0x6c, 0xd3, 0x40, 0x18, 0xcd, 0xc8, 0xc8, 0xd8, 0xb1, 0x63, 0x47, 0x16, 0x24, 0x46, 0x46, 0xc6, 0x8e, 0x8c, 0x8c, 0x8c, 0x8c, 0x65, 0x4b, 0x23, 0xcb, 0xb8, 0xa9, 0xe3, 0xd8, 0xae, 0x4d, 0x2a, 0x16, 0xd8, 0x18, 0x19, 0x11, 0x13, 0x03, 0x03, 0x23, 0x13, 0x02, 0x09, 0x09, 0x46, 0x04, 0x12, 0x22, 0xb0, 0x00, 0x12, 0x12, 0xdc, 0x3b, 0xfb, 0x25, 0x5f, 0x2e, 0x77, 0xf6, 0x9d, 0x53, 0x18, 0x4e, 0x6d, 0x1c, 0xe7, 0xee, 0x7d, 0xef, 0x7b, 0xdf, 0xdf, 0x8d, 0x8e, 0x8f, 0x8f, 0x47, 0x43, 0xd6, 0x78, 0x3c, 0xde, 0x8f, 0xe3, 0xe4, 0xf6, 0xc9, 0xc9, 0xe9, 0x38, 0xcb, 0xcb, 0xe7, 0xe6, 0x3a, 0x9d, 0xcd, 0xe7, 0xf8, 0x2e, 0x8a, 0xa2, 0x2b, 0x43, 0xcf, 0xc0, 0x0a, 0x05, 0xb5, 0x37, 0x4d, 0xb3, 0x7b, 0x69, 0x71, 0xf6, 0xea, 0xac, 0x3e, 0xff, 0xe3, 0xbb, 0xf2, 0xe2, 0xfe, 0xc7, 0x69, 0x9a, 0x2e, 0x26, 0x93, 0xc9, 0xf5, 0x7f, 0x02, 0x50, 0x01, 0xbb, 0x0c, 0x36, 0xf2, 0xb2, 0xfe, 0x21, 0x0f, 0x06, 0x53, 0x78, 0x9e, 0x24, 0xd3, 0x23, 0x1c, 0xce, 0x45, 0x66, 0xd3, 0x2c, 0x7f, 0x5c, 0x56, 0xe7, 0x5f, 0xe5, 0x6f, 0x66, 0xb3, 0xf2, 0xc9, 0x78, 0x1c, 0x1d, 0x5c, 0x18, 0xc0, 0x28, 0x4a, 0x6e, 0x82, 0x01, 0x09, 0x0a, 0xcf, 0x00, 0xda, 0x66, 0x88, 0x04, 0x9a, 0x24, 0xc9, 0x25, 0x3c, 0x9f, 0xc4, 0xf1, 0x8d, 0x74, 0x36, 0x7f, 0x28, 0x81, 0x42, 0x02, 0xfc, 0x7e, 0x30, 0x40, 0x6c, 0xb2, 0x72, 0x53, 0x5e, 0xbd, 0xc1, 0x41, 0xb6, 0xf7, 0xf0, 0x1c, 0xc0, 0x4d, 0xd7, 0x82, 0x3d, 0x18, 0xb3, 0x36, 0x20, 0x3a, 0x00, 0x83, 0xeb, 0x3d, 0xcf, 0x5e, 0x42, 0x36, 0xc1, 0x00, 0xc1, 0x84, 0x3c, 0x10, 0xee, 0xf2, 0x31, 0xc2, 0xaa, 0x3f, 0x25, 0x0b, 0x93, 0x6d, 0xb0, 0x4b, 0xd7, 0xc3, 0x3b, 0x5d, 0x81, 0x64, 0x7d, 0x48, 0x70, 0xd8, 0x5c, 0x32, 0x60, 0x2e, 0x04, 0x8c, 0x4f, 0x90, 0x38, 0xe4, 0xb0, 0x0f, 0xaf, 0x90, 0x69, 0x7c, 0xf6, 0x02, 0x48, 0x46, 0x1a, 0x70, 0x6e, 0xcb, 0xf0, 0x9d, 0x19, 0x34, 0xb6, 0x05, 0x97, 0x76, 0x05, 0x1f, 0x33, 0x02, 0xfe, 0xda, 0x34, 0xb9, 0x15, 0x10, 0xdc, 0x38, 0x8e, 0xe3, 0xc3, 0x2e, 0x6d, 0xc0, 0xed, 0x3e, 0xec, 0xf5, 0xe5, 0x41, 0xcd, 0x64, 0x1b, 0x84, 0x36, 0x63, 0x56, 0xff, 0x00, 0x3d, 0x5f, 0x44, 0xda, 0xe8, 0x8b, 0xae, 0x2c, 0xcf, 0x9f, 0xee, 0xc2, 0x9e, 0xe1, 0x8d, 0x6b, 0xf4, 0x86, 0x49, 0xcc, 0x96, 0x6b, 0x41, 0xb5, 0xcf, 0xa6, 0x32, 0x1a, 0x87, 0xb2, 0x67, 0x93, 0x96, 0x79, 0xfe, 0xaa, 0x42, 0xb8, 0x2c, 0x18, 0x1a, 0x20, 0xbe, 0xec, 0xc9, 0x2a, 0x45, 0x0f, 0x46, 0x71, 0x7c, 0x6b, 0x03, 0x20, 0xf5, 0x84, 0xbc, 0x14, 0xb2, 0xe1, 0x45, 0xb1, 0xc7, 0x15, 0x27, 0xd3, 0x3b, 0xcc, 0xb9, 0x1b, 0x00, 0x19, 0x49, 0x12, 0xf9, 0x2e, 0x6e, 0xf6, 0x95, 0x89, 0x2d, 0xaa, 0xd7, 0xa9, 0xa9, 0x29, 0x87, 0x3a, 0x8a, 0x64, 0xbe, 0x82, 0xe5, 0x08, 0x00, 0x1c, 0xde, 0xe7, 0x6e, 0x6c, 0x62, 0xd6, 0x5a, 0x2c, 0xb8, 0xdf, 0x76, 0x38, 0x18, 0x92, 0xdd, 0x0e, 0x82, 0xc3, 0x95, 0x83, 0x19, 0xa8, 0x23, 0x14, 0x76, 0xd6, 0x58, 0x19, 0xc9, 0x92, 0x8d, 0x2e, 0xa0, 0x32, 0x02, 0xb9, 0xd4, 0xe6, 0x77, 0x65, 0x76, 0x80, 0x84, 0x6c, 0x86, 0xe8, 0xfd, 0x55, 0x8d, 0x96, 0x89, 0x7c, 0xed, 0xe6, 0x46, 0x6e, 0x23, 0xb4, 0x41, 0x2c, 0x67, 0xa8, 0xa9, 0x2e, 0x4d, 0xb9, 0x80, 0xc2, 0x03, 0x59, 0x56, 0xbd, 0x9e, 0x97, 0xf5, 0xe7, 0xf9, 0xbc, 0x7c, 0x91, 0x17, 0xd5, 0x5b, 0xa5, 0xa1, 0x4f, 0x28, 0x67, 0x38, 0x18, 0x07, 0xf5, 0x45, 0x3b, 0xc9, 0xa1, 0xc1, 0xac, 0x2e, 0x1a, 0x20, 0x75, 0x04, 0x26, 0xa1, 0xc1, 0xde, 0xde, 0x4e, 0x09, 0x98, 0xed, 0x95, 0x06, 0xa7, 0x36, 0x87, 0x91, 0xb2, 0x0a, 0xc0, 0x90, 0xa2, 0xa8, 0x97, 0x79, 0x59, 0xbe, 0xf3, 0xed, 0x19, 0xc1, 0x1c, 0x0d, 0xe6, 0x33, 0x0d, 0x90, 0x01, 0x82, 0x4d, 0x7d, 0x00, 0x9a, 0xab, 0x50, 0x96, 0x02, 0x1c, 0x74, 0x07, 0x57, 0x93, 0x8d, 0xd3, 0x59, 0xf6, 0x40, 0x7d, 0xfe, 0x1d, 0xd2, 0xd4, 0xd2, 0xc8, 0x0d, 0x80, 0x45, 0x59, 0x7d, 0xc0, 0x07, 0x30, 0x82, 0x00, 0x09, 0x05, 0x38, 0x9b, 0x97, 0xcf, 0xb4, 0x2b, 0x85, 0x0e, 0x69, 0x6c, 0x59, 0x55, 0x5f, 0x42, 0xf6, 0xa2, 0x84, 0x88, 0x49, 0x03, 0x64, 0x47, 0x01, 0xfd, 0xd9, 0x82, 0xa4, 0x5f, 0x3f, 0xf5, 0x7b, 0x99, 0xaa, 0xda, 0x6c, 0xb0, 0xd7, 0x04, 0xc6, 0xe2, 0x67, 0xc8, 0x5e, 0x8c, 0x7e, 0x1a, 0xab, 0x01, 0x32, 0xac, 0x99, 0x03, 0xfb, 0xfa, 0xbb, 0x2d, 0x17, 0x17, 0xd5, 0x12, 0x4d, 0x06, 0x8c, 0x03, 0x03, 0xd0, 0x90, 0xae, 0x0a, 0x2a, 0x50, 0xd2, 0x34, 0x7d, 0xc4, 0xa1, 0xca, 0x67, 0x2f, 0x46, 0xf4, 0xa6, 0x06, 0xdb, 0x56, 0x9c, 0x4d, 0x29, 0x5e, 0x20, 0xc5, 0x3e, 0xc2, 0x86, 0x34, 0x8a, 0xb2, 0x5e, 0x42, 0x73, 0x30, 0x12, 0x2c, 0x94, 0x55, 0xfd, 0xdd, 0xcc, 0x85, 0x9c, 0x6b, 0x5c, 0xe9, 0x86, 0x63, 0x80, 0x94, 0x99, 0x06, 0x88, 0x88, 0xd4, 0xe8, 0xd5, 0x80, 0x23, 0x13, 0x70, 0x97, 0xab, 0x75, 0x2b, 0x2f, 0xaa, 0x8e, 0x3a, 0xfc, 0x6a, 0xf3, 0x7c, 0xf1, 0x0d, 0x81, 0xa1, 0xb4, 0xf7, 0xcb, 0x55, 0xea, 0x00, 0x94, 0x01, 0x65, 0xee, 0x0b, 0x99, 0xb1, 0xe5, 0x63, 0xb9, 0xdb, 0xc8, 0x3b, 0x32, 0x55, 0x34, 0x1b, 0xa5, 0x0b, 0x09, 0x14, 0xff, 0x83, 0x35, 0xb3, 0xb1, 0x84, 0x41, 0x36, 0x23, 0x5c, 0x5d, 0x32, 0x6b, 0xb9, 0x94, 0x13, 0x3c, 0xa9, 0xb5, 0xdc, 0x7a, 0x14, 0x67, 0xaf, 0x6a, 0x31, 0x41, 0x0c, 0x99, 0x5b, 0x9b, 0xbc, 0xd7, 0x54, 0x23, 0x5b, 0x72, 0xf7, 0x99, 0xdc, 0xe4, 0xa2, 0x04, 0x88, 0x65, 0x64, 0x43, 0x1d, 0xba, 0xba, 0x9a, 0x57, 0x80, 0xf7, 0x37, 0x34, 0x3e, 0xa4, 0xa7, 0x36, 0xba, 0x19, 0x0a, 0xb3, 0x9d, 0xc0, 0xf6, 0x43, 0xc0, 0xf5, 0xe5, 0x4e, 0x44, 0xb0, 0xef, 0x5e, 0x4c, 0x55, 0x70, 0xfd, 0x56, 0x47, 0xcd, 0x92, 0x17, 0xda, 0x68, 0xfa, 0x74, 0xd6, 0x7e, 0x86, 0xb6, 0xc1, 0xa1, 0xd8, 0x93, 0xb3, 0xb2, 0x95, 0x09, 0x5f, 0x2d, 0xfa, 0x56, 0x9e, 0xbe, 0xe1, 0x5c, 0x57, 0xa2, 0x36, 0x0e, 0x58, 0x93, 0xad, 0x53, 0x1d, 0xdb, 0xf8, 0xbe, 0x08, 0x0c, 0x61, 0xcf, 0xcc, 0x0e, 0xe6, 0xc2, 0x77, 0x4c, 0xe4, 0xc8, 0xbf, 0xe6, 0xbb, 0x5b, 0x2f, 0xb3, 0x3d, 0x42, 0x1e, 0xb2, 0x0d, 0xdc, 0xa1, 0xec, 0xc9, 0xfc, 0x6a, 0x9f, 0x6d, 0x9a, 0x76, 0xaf, 0xd1, 0xff, 0xf6, 0xa5, 0x52, 0xe7, 0xf0, 0x02, 0xd1, 0xba, 0x98, 0x34, 0x2f, 0x83, 0xdc, 0xd7, 0x1e, 0xee, 0x9b, 0x2c, 0x82, 0xeb, 0x1a, 0xd6, 0x9c, 0xec, 0x18, 0x77, 0x27, 0xce, 0xd6, 0xbc, 0x0b, 0x9c, 0xeb, 0xda, 0xc4, 0xbc, 0xfb, 0x31, 0x75, 0xe7, 0x75, 0xbb, 0x05, 0xe6, 0x18, 0xf6, 0x38, 0x0c, 0xfa, 0x94, 0x2e, 0x97, 0xb7, 0x10, 0xb6, 0x04, 0x6d, 0x33, 0x4a, 0xff, 0x4e, 0x95, 0x48, 0x7a, 0x08, 0x24, 0xf4, 0xcd, 0x3d, 0x9d, 0x41, 0x00, 0x4d, 0x42, 0x43, 0x66, 0xa9, 0x23, 0x50, 0x30, 0x8d, 0x9c, 0xc5, 0x41, 0x48, 0x8f, 0x0d, 0x8e, 0x0c, 0x00, 0x83, 0x64, 0x4b, 0xd6, 0x68, 0xbc, 0xff, 0x22, 0xd3, 0x2b, 0xd7, 0xe9, 0x0b, 0x48, 0xe3, 0xda, 0x17, 0xd5, 0x83, 0xdd, 0x8c, 0x2d, 0x98, 0x9a, 0x06, 0x58, 0x81, 0x32, 0x6e, 0x59, 0x9b, 0xa8, 0x9e, 0x1e, 0xf9, 0x96, 0xc0, 0xa0, 0x92, 0xa6, 0xdd, 0xd3, 0x36, 0xb8, 0xa1, 0x0b, 0xec, 0x83, 0xed, 0xae, 0xcc, 0xb0, 0x33, 0x40, 0xd9, 0xbd, 0x80, 0xbd, 0xbe, 0xcb, 0x74, 0xe4, 0xb5, 0xa1, 0x97, 0xe7, 0x3b, 0x01, 0xfc, 0x9f, 0xeb, 0x2f, 0x07, 0xfe, 0x95, 0x85, 0x7c, 0xe7, 0x76, 0x56, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82 };
const size_t aboutIconContentSize = sizeof(aboutIconContent);
const char* aboutIconUrl = { "" };

/**
 * The AllJoyn Message Loop
 */

int AJ_Main(void)
{
    AJ_Status status = AJ_OK;
    uint8_t isUnmarshalingSuccessful = FALSE;
    AJSVC_ServiceStatus serviceStatus;
    AJ_Message msg;
    uint8_t forcedDisconnnect = FALSE;
    uint8_t rebootRequired = FALSE;

    AJ_Initialize();

    AJ_AboutSetIcon(aboutIconContent, aboutIconContentSize, aboutIconMimetype, aboutIconUrl);

    status = PropertyStore_Init();
    if (status != AJ_OK) {
        goto Exit;
    }

#ifdef EVENTS_AND_ACTIONS
    status = EventsAndActions_Init(propertyStoreDefaultLanguages);
    if (status != AJ_OK) {
        goto Exit;
    }
#endif

    status = AJServices_Init(AJ_ABOUT_SERVICE_PORT, deviceManufactureName, deviceProductName);
    if (status != AJ_OK) {
        goto Exit;
    }
    SetBusAuthPwdCallback(MyBusAuthPwdCB);

    while (TRUE) {
        status = AJ_OK;
        serviceStatus = AJSVC_SERVICE_STATUS_NOT_HANDLED;

        if (!isBusConnected) {
            status = AJSVC_RoutingNodeConnect(&busAttachment, ROUTING_NODE_NAME, AJAPP_CONNECT_TIMEOUT, AJAPP_CONNECT_PAUSE, AJAPP_BUS_LINK_TIMEOUT, &isBusConnected);
            if (!isBusConnected) { // Failed to connect to Routing Node?
                continue; // Retry establishing connection to Routing Node.
            }
            /* Setup password based authentication listener for secured peer to peer connections */
            AJ_BusSetPasswordCallback(&busAttachment, PasswordCallback);
        }

        status = AJApp_ConnectedHandler(&busAttachment, AJAPP_MAX_INIT_ATTEMPTS, AJAPP_SLEEP_TIME);

        if (status == AJ_OK) {
            status = AJ_UnmarshalMsg(&busAttachment, &msg, AJAPP_UNMARSHAL_TIMEOUT);
            isUnmarshalingSuccessful = (status == AJ_OK);

            if (status == AJ_ERR_TIMEOUT) {
                if (AJ_ERR_LINK_TIMEOUT == AJ_BusLinkStateProc(&busAttachment)) {
                    status = AJ_ERR_READ;             // something's not right. force disconnect
                } else {                              // nothing on bus, do our own thing
#ifdef EVENTS_AND_ACTIONS
                    EventsAndActions_DoWork(&busAttachment);
#endif
                    AJApp_DoWork(&busAttachment);
                    continue;
                }
            }

            if (isUnmarshalingSuccessful) {
#ifdef EVENTS_AND_ACTIONS
                if (serviceStatus == AJSVC_SERVICE_STATUS_NOT_HANDLED) {
                    serviceStatus = EventsAndActionsMessageProcessor(&busAttachment, &msg, &status);
                }
#endif
                if (serviceStatus == AJSVC_SERVICE_STATUS_NOT_HANDLED) {
                    serviceStatus = AJApp_MessageProcessor(&busAttachment, &msg, &status);
                }
                if (serviceStatus == AJSVC_SERVICE_STATUS_NOT_HANDLED) {
                    //Pass to the built-in bus message handlers
                    status = AJ_BusHandleBusMessage(&msg);
                }
                AJ_NotifyLinkActive();
            }

            //Unmarshaled messages must be closed to free resources
            AJ_CloseMsg(&msg);
        }

        if (status == AJ_ERR_READ || status == AJ_ERR_RESTART || status == AJ_ERR_RESTART_APP) {
            if (isBusConnected) {
                forcedDisconnnect = (status != AJ_ERR_READ);
                rebootRequired = (status == AJ_ERR_RESTART_APP);
                AJApp_DisconnectHandler(&busAttachment, forcedDisconnnect);
                AJSVC_RoutingNodeDisconnect(&busAttachment, forcedDisconnnect, AJAPP_SLEEP_TIME, AJAPP_SLEEP_TIME, &isBusConnected);
                if (rebootRequired) {
                    AJ_Reboot();
                }
            }
        }
    }     // while (TRUE)

    return 0;

Exit:

    return (1);
}

#ifdef AJ_MAIN
int main()
{
    return AJ_Main();
}
#endif
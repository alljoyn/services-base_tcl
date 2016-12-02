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

#ifndef CONTROLPANELPROVIDED_H_
#define CONTROLPANELPROVIDED_H_

#include <ajtcl/alljoyn.h>
#include <ajtcl/services/Common/DateTimeUtil.h>
#include "ControlPanelGenerated.h"

//////////////////////////////////////////////////////

void disableFan();
void enableFan();
void disableTempSelect();
void enableTempSelect();

const char* getNotificationString();
const char* getNotificationActionObjPath();
uint16_t isThereANotificationToSend();

uint16_t getCurrentTargetTemp();

void checkTargetTempReached();

void setTemperatureFieldUpdate();
void setStatusFieldUpdate();
void setTempSelectorFieldUpdate();
void setFanSpeedSelectorFieldUpdate();

//char const* getCurrentTemperatureString(uint16_t lang);
//char const* getCurrentHumidityString(uint16_t lang);

void* getCurrentTemperatureString(PropertyWidget* thisWidget);
void setCurrentTemperatureString(char const* newTemp);
void* getCurrentHumidityString(PropertyWidget* thisWidget);
void setCurrentHumidityString(char const* newHumidity);

void* getTargetTemperature(PropertyWidget* thisWidget);
void setTargetTemperature(uint16_t newTemp);

void* getCurrentMode(PropertyWidget* thisWidget);
void setCurrentMode(uint16_t newMode);

void* getFanSpeed(PropertyWidget* thisWidget);
void setFanSpeed(uint16_t newSpeed);

void* getStatusString(PropertyWidget* thisWidget);
void setStatusString(const char* newStatusString);

void onTurnFanOn(ExecuteActionContext* context, uint8_t accepted);
void onTurnFanOff(ExecuteActionContext* context, uint8_t accepted);

//void simulateTemperatureChange();
uint8_t checkForUpdatesToSend();
uint8_t checkForEventsToSend();

#endif /* CONTROLPANELPROVIDED_H_ */

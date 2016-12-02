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

#ifndef DATETIMEUTIL_H_
#define DATETIMEUTIL_H_

/** @defgroup DateTimeUtil Date and Time Utilities
 * details Structs and Functions that assist in Un/Marshaling
 * Date and Time Properties from/to a message.
 *  @{
 */

#include <ajtcl/alljoyn.h>

/**
 * DatePropertyValue structure
 */
typedef struct {
    uint16_t mDay;     //!< The day of the month value i.e. 1 for 1st of the month
    uint16_t month;    //!< The month value i.e. 3 for March
    uint16_t fullYear; //!< The full year value i.e. 2014 and not 14
} DatePropertyValue;

/**
 * TimePropertyValue structure
 */
typedef struct {
    uint16_t hour;   //!< The hour value as 24 hours
    uint16_t minute; //!< The minute value
    uint16_t second; //!< The second valur
} TimePropertyValue;

/**
 * Marshal DatePropertyValue into given reply message
 * @param datePropertyValue - value to marshal
 * @param reply - message to marshal into
 * @return aj_status - success/failure
 */
AJ_Status marshalDatePropertyValue(DatePropertyValue* datePropertyValue, AJ_Message* reply);

/**
 * Marshal TimePropertyValue into given reply message
 * @param timePropertyValue - value to marshal
 * @param reply - message to marshal into
 * @return aj_status - success/failure
 */
AJ_Status marshalTimePropertyValue(TimePropertyValue* timePropertyValue, AJ_Message* reply);

/**
 * Unmarshal DatePropertyValue from given message
 * @param datePropertyValue - value to fill with unmarshalled content
 * @param message - message to unmarshal
 * @return aj_status - success/failure
 */
AJ_Status unmarshalDatePropertyValue(DatePropertyValue* datePropertyValue, AJ_Message* message);

/**
 * Unmarshal TimePropertyValue from given message
 * @param timePropertyValue - value to fill with unmarshalled content
 * @param message - message to unmarshal
 * @return aj_status - success/failure
 */
AJ_Status unmarshalTimePropertyValue(TimePropertyValue* timePropertyValue, AJ_Message* message);

/** @} */
#endif /* DATETIMEUTIL_H_ */
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

#ifndef HTTPCONTROL_H_
#define HTTPCONTROL_H_

/** @defgroup HttpControl Http Control
 * details Http Control Struct and Functions that assist in Marshaling
 * HttpControl into a message.
 *  @{
 */

#include <alljoyn.h>

/**
 * HttpControl structure - used to define a url for a controlpanel
 */
typedef struct {
    const char* url;         //!< The url of the Http control
    const char* (*getUrl)(); //!< Getter for the url of the Http control
} HttpControl;

/**
 * Initialize the HttpControl structure
 * @param httpControl - pointer to HttpControl structure
 */
void initializeHttpControl(HttpControl* httpControl);

/**
 * Marshal HttpControlUrl into given reply message
 * @param httpControl - httpcontrol to marshal
 * @param reply - the reply message to fill
 * @param language - the language requested
 * @return aj_status - success/failure
 */
AJ_Status marshalHttpControlUrl(HttpControl* httpControl, AJ_Message* reply, uint16_t language);

/** @} */
#endif /* HTTPCONTROL_H_ */
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

#ifndef _SERVICES_HANDLERS_H_
#define _SERVICES_HANDLERS_H_

#include <alljoyn.h>
#include <alljoyn/services_common/ServicesCommon.h>

/**
 * Establish connection to named Routing Node
 * @param busAttachment
 * @param routingNodeName
 * @param connectTimeout
 * @param connectPause
 * @param busLinkTimeout
 * @param isConnected - state of connection to Routing Node after connect is performed
 * @return ajStatus - status of last request to Routing Node
 */
AJ_Status AJSVC_RoutingNodeConnect(AJ_BusAttachment* busAttachment, const char* routingNodeName, uint32_t connectTimeout, uint32_t connectPause, uint32_t busLinkTimeout, uint8_t* isConnected);

/**
 * Functions to call after the Routing Node is Connected
 * @param busAttachment
 * @return ajStatus - status of last request to Routing Node
 */
AJ_Status AJSVC_ConnectedHandler(AJ_BusAttachment* busAttachment);

/**
 * Process an incoming message and dispatch handling to relevant services
 * @param busAttachment
 * @param msg
 * @param status
 * @return servicestatus - shows if the message was processed or not
 */
AJSVC_ServiceStatus AJSVC_MessageProcessorAndDispatcher(AJ_BusAttachment* busAttachment, AJ_Message* msg, AJ_Status* status);

/**
 * Session request accept/reject function for service targetted session
 * @param port
 * @param sessionId
 * @param joiner
 */
uint8_t AJSVC_CheckSessionAccepted(uint16_t port, uint32_t sessionId, char* joiner);

/**
 * Shutdown services. Should be called on bus disconnect
 * @param busAttachment
 * @return ajStatus - status of last request to Routing Node
 */
AJ_Status AJSVC_DisconnectHandler(AJ_BusAttachment* busAttachment);

/**
 * Disconnect from Routing Node
 * @param busAttachment
 * @param disconnectWiFi
 * @param preDisconnectPause - a small pause before disconnect to allow for outgoing message to be dispatched
 * @param postDisconnectPause - a small pause after disconnect to allow for system to stablize
 * @param isConnected - state of connection to Rounting Node after disconnect is performed
 * @return ajStatus - status of last request to Routing Node
 */
AJ_Status AJSVC_RoutingNodeDisconnect(AJ_BusAttachment* busAttachment, uint8_t disconnectWiFi, uint32_t preDisconnectPause, uint32_t postDisconnectPause, uint8_t* isConnected);

#endif /* _SERVICES_HANDLERS_H_ */
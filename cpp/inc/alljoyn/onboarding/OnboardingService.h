/******************************************************************************
 * Copyright (c) 2013, AllSeen Alliance. All rights reserved.
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
#ifndef _ONBOARDINGSERVICE_H
#define _ONBOARDINGSERVICE_H

#include <alljoyn/BusObject.h>
#include <alljoyn/Status.h>
#include  <alljoyn/onboarding/OnboardingControllerAPI.h>
#include <alljoyn/services_common/GenericLogger.h>
#include <alljoyn/services_common/ServicesLoggerImpl.h>


namespace ajn {
namespace services {

/**
 * OnboardingService is an AllJoyn BusObject that implements the org.alljoyn.Onboarding standard interface.
 * Applications that provide AllJoyn IoE services use an instance of this class to enable onboarding of
 * the device.
 */
class OnboardingService : public ajn::BusObject {

  public:

    /**
     * Constructor of OnboardingService
     * @param[in] bus is a reference to BusAttachment
     * @param[in] pOnboardingControllerAPI is a reference to OnboardingControllerAPI
     */
    OnboardingService(ajn::BusAttachment& bus, OnboardingControllerAPI& pOnboardingControllerAPI);

    /**
     * Destructor of OnboardingService
     */
    ~OnboardingService() { }

    /**
     * Register the OnboardingService on the alljoyn bus.
     * @return status.
     */
    QStatus Register();
    /**
     *  Unregister the OnboardingService from  the alljoyn bus .
     */
    void Unregister();

    /**
     * Receive GenericLogger* to use for logging
     * @param logger Implementation of GenericLogger
     * @return previous logger
     */
    GenericLogger* setLogger(GenericLogger* logger);

    /**
     * Get the currently-configured logger implementation
     * @return logger Implementation of GenericLogger
     */
    GenericLogger* getLogger();

    /**
     * Set log level filter for subsequent logging messages
     * @param newLogLevel enum value
     * @return logLevel enum value that was in effect prior to this change
     */
    Log::LogLevel setLogLevel(Log::LogLevel newLogLevel);

    /**
     * Get log level filter value currently in effect
     * @return logLevel enum value currently in effect
     */
    Log::LogLevel getLogLevel();


    /**
     * A callback passed to the Generic Logger when the default logger is replaced by a different logger
     * @param type - message type
     * @param module - module of the message
     * @param msg - message
     * @param context - context passed in by the application
     */
    static void GenericLoggerCallBack(DbgMsgType type, const char* module, const char* msg, void* context);

  private:

    /**
     * Handles the ConfigureWiFi method
     * @param member
     * @param msg reference of alljoyn Message
     */
    void ConfigureWiFiHandler(const ajn::InterfaceDescription::Member* member, ajn::Message& msg);
    /**
     * Handles the Connect method
     * @param member
     * @param msg reference of alljoyn Message
     */
    void ConnectHandler(const ajn::InterfaceDescription::Member* member, ajn::Message& msg);
    /**
     * Handles the Offboard method
     * @param member
     * @param msg reference of alljoyn Message
     */
    void OffboardHandler(const ajn::InterfaceDescription::Member* member, ajn::Message& msg);
    /**
     * Handles the GetScanInfo method
     * @param member
     * @param msg reference of alljoyn Message
     */
    void GetScanInfoHandler(const ajn::InterfaceDescription::Member* member, ajn::Message& msg);
    /**
     * Handles the Get Property requests
     * @param ifcName
     * @param propName
     * @param val
     * @return
     */
    QStatus Get(const char*ifcName, const char*propName, MsgArg& val);
    /**
     * check if method reply is needed and print if encounter an error
     * @param Message&
     * @param const MsgArg*
     * @param numArgs
     * @return
     */
    void Check_MethodReply(const Message& msg, const MsgArg* args = NULL, size_t numArgs = 0);
    /**
     * check if method reply is needed and print if encounter an error
     * @param Message&
     * @param QStatus
     * @return
     */
    void Check_MethodReply(const Message& msg, QStatus status);
    /**
     *	pointer of BusAttachment
     */
    ajn::BusAttachment* m_BusAttachment;
    /**
     * pointer of OnboardingControllerAPI
     */
    OnboardingControllerAPI& m_OnboardingController;

    /**
     * Logger that is used in library
     */
    GenericLogger* logger;

    /**
     * Default Logger that is used in library
     */
    ServicesLoggerImpl onboardingLogger;

};

}
}

#endif /*_ONBOARDINGSERVICE_H*/

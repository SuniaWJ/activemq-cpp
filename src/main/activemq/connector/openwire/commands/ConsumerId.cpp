/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/ConsumerId.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>
#include <memory>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for ConsumerId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ConsumerId::ConsumerId()
{
    this->connectionId = "";
    this->sessionId = 0;
    this->value = 0;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId::~ConsumerId()
{
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* ConsumerId::cloneDataStructure() const {
    std::auto_ptr<ConsumerId> consumerId( new ConsumerId() );

    // Copy the data from the base class or classes
    consumerId->copyDataStructure( this );

    return consumerId.release();
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const ConsumerId* srcPtr = dynamic_cast<const ConsumerId*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ConsumerId::copyDataStructure - src is NULL or invalid" );
    }
    this->setConnectionId( srcPtr->getConnectionId() );
    this->setSessionId( srcPtr->getSessionId() );
    this->setValue( srcPtr->getValue() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ConsumerId::getDataStructureType() const {
    return ConsumerId::ID_CONSUMERID;
}

////////////////////////////////////////////////////////////////////////////////
std::string ConsumerId::toString() const {

    ostringstream stream;

    stream << "Begin Class = ConsumerId" << std::endl;
    stream << " Value of ConsumerId::ID_CONSUMERID = 122" << std::endl;
    stream << " Value of ConnectionId = " << this->getConnectionId() << std::endl;
    stream << " Value of SessionId = " << this->getSessionId() << std::endl;
    stream << " Value of Value = " << this->getValue() << std::endl;
    stream << BaseDataStructure::toString();
    stream << "End Class = ConsumerId" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerId::equals( const DataStructure* value ) const {
    const ConsumerId* valuePtr = dynamic_cast<const ConsumerId*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getConnectionId() != valuePtr->getConnectionId() ) {
        return false;
    }
    if( this->getSessionId() != valuePtr->getSessionId() ) {
        return false;
    }
    if( this->getValue() != valuePtr->getValue() ) {
        return false;
    }
    if( !BaseDataStructure::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConsumerId::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConsumerId::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::setConnectionId(const std::string& connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
long long ConsumerId::getSessionId() const {
    return sessionId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::setSessionId(long long sessionId ) {
    this->sessionId = sessionId;
}

////////////////////////////////////////////////////////////////////////////////
long long ConsumerId::getValue() const {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::setValue(long long value ) {
    this->value = value;
}


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
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

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
DataStructure* ConsumerId::cloneDataStructure() const {
    ConsumerId* consumerId = new ConsumerId();

    // Copy the data from the base class or classes
    consumerId->copyDataStructure( this );

    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const ConsumerId* srcPtr = dynamic_cast<const ConsumerId*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
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
const long long ConsumerId::getSessionId() const {
    return sessionId;
}

////////////////////////////////////////////////////////////////////////////////
long long ConsumerId::getSessionId() {
    return sessionId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::setSessionId(long long sessionId ) {
    this->sessionId = sessionId;
}

////////////////////////////////////////////////////////////////////////////////
const long long ConsumerId::getValue() const {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
long long ConsumerId::getValue() {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerId::setValue(long long value ) {
    this->value = value;
}


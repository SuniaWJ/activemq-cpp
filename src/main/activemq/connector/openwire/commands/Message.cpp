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
#include <activemq/connector/openwire/commands/Message.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for Message
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
Message::Message()
{
    this->producerId = NULL;
    this->destination = NULL;
    this->transactionId = NULL;
    this->originalDestination = NULL;
    this->messageId = NULL;
    this->originalTransactionId = NULL;
    this->groupID = "";
    this->groupSequence = 0;
    this->correlationId = "";
    this->persistent = false;
    this->expiration = 0;
    this->priority = 0;
    this->replyTo = NULL;
    this->timestamp = 0;
    this->type = "";
    this->dataStructure = NULL;
    this->targetConsumerId = NULL;
    this->compressed = false;
    this->redeliveryCounter = 0;
    this->arrival = 0;
    this->userID = "";
    this->recievedByDFBridge = false;
    this->droppable = false;
}

////////////////////////////////////////////////////////////////////////////////
Message::~Message()
{
    delete this->producerId;
    delete this->destination;
    delete this->transactionId;
    delete this->originalDestination;
    delete this->messageId;
    delete this->originalTransactionId;
    delete this->replyTo;
    delete this->dataStructure;
    delete this->targetConsumerId;
    for( size_t ibrokerPath = 0; ibrokerPath < brokerPath.size(); ++ibrokerPath ) {
        delete brokerPath[ibrokerPath];
    }
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* Message::cloneDataStructure() const {
    Message* message = new Message();

    // Copy the data from the base class or classes
    message->copyDataStructure( this );

    return message;
}

////////////////////////////////////////////////////////////////////////////////
void Message::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const Message* srcPtr = dynamic_cast<const Message*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "Message::copyDataStructure - src is NULL or invalid" );
    }
    this->setProducerId( 
        dynamic_cast<ProducerId*>( 
            srcPtr->getProducerId()->cloneDataStructure() ) );
    this->setDestination( 
        dynamic_cast<ActiveMQDestination*>( 
            srcPtr->getDestination()->cloneDataStructure() ) );
    this->setTransactionId( 
        dynamic_cast<TransactionId*>( 
            srcPtr->getTransactionId()->cloneDataStructure() ) );
    this->setOriginalDestination( 
        dynamic_cast<ActiveMQDestination*>( 
            srcPtr->getOriginalDestination()->cloneDataStructure() ) );
    this->setMessageId( 
        dynamic_cast<MessageId*>( 
            srcPtr->getMessageId()->cloneDataStructure() ) );
    this->setOriginalTransactionId( 
        dynamic_cast<TransactionId*>( 
            srcPtr->getOriginalTransactionId()->cloneDataStructure() ) );
    this->setGroupID( srcPtr->getGroupID() );
    this->setGroupSequence( srcPtr->getGroupSequence() );
    this->setCorrelationId( srcPtr->getCorrelationId() );
    this->setPersistent( srcPtr->isPersistent() );
    this->setExpiration( srcPtr->getExpiration() );
    this->setPriority( srcPtr->getPriority() );
    this->setReplyTo( 
        dynamic_cast<ActiveMQDestination*>( 
            srcPtr->getReplyTo()->cloneDataStructure() ) );
    this->setTimestamp( srcPtr->getTimestamp() );
    this->setType( srcPtr->getType() );
    this->setContent( srcPtr->getContent() );
    this->setMarshalledProperties( srcPtr->getMarshalledProperties() );
    this->setDataStructure( 
        dynamic_cast<DataStructure*>( 
            srcPtr->getDataStructure()->cloneDataStructure() ) );
    this->setTargetConsumerId( 
        dynamic_cast<ConsumerId*>( 
            srcPtr->getTargetConsumerId()->cloneDataStructure() ) );
    this->setCompressed( srcPtr->isCompressed() );
    this->setRedeliveryCounter( srcPtr->getRedeliveryCounter() );
    for( size_t ibrokerPath = 0; ibrokerPath < srcPtr->getBrokerPath().size(); ++ibrokerPath ) {
        this->getBrokerPath().push_back( 
            dynamic_cast<BrokerId*>( 
                srcPtr->getBrokerPath()[ibrokerPath]->cloneDataStructure() ) );
    }
    this->setArrival( srcPtr->getArrival() );
    this->setUserID( srcPtr->getUserID() );
    this->setRecievedByDFBridge( srcPtr->isRecievedByDFBridge() );
    this->setDroppable( srcPtr->isDroppable() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char Message::getDataStructureType() const {
    return Message::ID_MESSAGE; 
}

////////////////////////////////////////////////////////////////////////////////
const ProducerId* Message::getProducerId() const {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
ProducerId* Message::getProducerId() {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setProducerId(ProducerId* producerId ) {
    this->producerId = producerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDestination(ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* Message::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* Message::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTransactionId(TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getOriginalDestination() const {
    return originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getOriginalDestination() {
    return originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setOriginalDestination(ActiveMQDestination* originalDestination ) {
    this->originalDestination = originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* Message::getMessageId() const {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* Message::getMessageId() {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setMessageId(MessageId* messageId ) {
    this->messageId = messageId;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* Message::getOriginalTransactionId() const {
    return originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* Message::getOriginalTransactionId() {
    return originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setOriginalTransactionId(TransactionId* originalTransactionId ) {
    this->originalTransactionId = originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getGroupID() const {
    return groupID;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getGroupID() {
    return groupID;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setGroupID(const std::string& groupID ) {
    this->groupID = groupID;
}

////////////////////////////////////////////////////////////////////////////////
const int Message::getGroupSequence() const {
    return groupSequence;
}

////////////////////////////////////////////////////////////////////////////////
int Message::getGroupSequence() {
    return groupSequence;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setGroupSequence(int groupSequence ) {
    this->groupSequence = groupSequence;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getCorrelationId() const {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getCorrelationId() {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setCorrelationId(const std::string& correlationId ) {
    this->correlationId = correlationId;
}

////////////////////////////////////////////////////////////////////////////////
const bool Message::isPersistent() const {
    return persistent;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isPersistent() {
    return persistent;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setPersistent(bool persistent ) {
    this->persistent = persistent;
}

////////////////////////////////////////////////////////////////////////////////
const long long Message::getExpiration() const {
    return expiration;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getExpiration() {
    return expiration;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setExpiration(long long expiration ) {
    this->expiration = expiration;
}

////////////////////////////////////////////////////////////////////////////////
const unsigned char Message::getPriority() const {
    return priority;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char Message::getPriority() {
    return priority;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setPriority(unsigned char priority ) {
    this->priority = priority;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getReplyTo() const {
    return replyTo;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getReplyTo() {
    return replyTo;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setReplyTo(ActiveMQDestination* replyTo ) {
    this->replyTo = replyTo;
}

////////////////////////////////////////////////////////////////////////////////
const long long Message::getTimestamp() const {
    return timestamp;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getTimestamp() {
    return timestamp;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTimestamp(long long timestamp ) {
    this->timestamp = timestamp;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getType() {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setType(const std::string& type ) {
    this->type = type;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& Message::getContent() const {
    return content;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& Message::getContent() {
    return content;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setContent(const std::vector<unsigned char>& content ) {
    this->content = content;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& Message::getMarshalledProperties() const {
    return marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& Message::getMarshalledProperties() {
    return marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setMarshalledProperties(const std::vector<unsigned char>& marshalledProperties ) {
    this->marshalledProperties = marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
const DataStructure* Message::getDataStructure() const {
    return dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* Message::getDataStructure() {
    return dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDataStructure(DataStructure* dataStructure ) {
    this->dataStructure = dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* Message::getTargetConsumerId() const {
    return targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* Message::getTargetConsumerId() {
    return targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTargetConsumerId(ConsumerId* targetConsumerId ) {
    this->targetConsumerId = targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
const bool Message::isCompressed() const {
    return compressed;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isCompressed() {
    return compressed;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setCompressed(bool compressed ) {
    this->compressed = compressed;
}

////////////////////////////////////////////////////////////////////////////////
const int Message::getRedeliveryCounter() const {
    return redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
int Message::getRedeliveryCounter() {
    return redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setRedeliveryCounter(int redeliveryCounter ) {
    this->redeliveryCounter = redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*>& Message::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*>& Message::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setBrokerPath(const std::vector<BrokerId*>& brokerPath ) {
    this->brokerPath = brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
const long long Message::getArrival() const {
    return arrival;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getArrival() {
    return arrival;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setArrival(long long arrival ) {
    this->arrival = arrival;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getUserID() const {
    return userID;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getUserID() {
    return userID;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setUserID(const std::string& userID ) {
    this->userID = userID;
}

////////////////////////////////////////////////////////////////////////////////
const bool Message::isRecievedByDFBridge() const {
    return recievedByDFBridge;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isRecievedByDFBridge() {
    return recievedByDFBridge;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setRecievedByDFBridge(bool recievedByDFBridge ) {
    this->recievedByDFBridge = recievedByDFBridge;
}

////////////////////////////////////////////////////////////////////////////////
const bool Message::isDroppable() const {
    return droppable;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isDroppable() {
    return droppable;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDroppable(bool droppable ) {
    this->droppable = droppable;
}


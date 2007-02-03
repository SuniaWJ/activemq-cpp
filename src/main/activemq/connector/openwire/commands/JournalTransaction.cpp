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
#include <activemq/connector/openwire/commands/JournalTransaction.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for JournalTransaction
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
JournalTransaction::JournalTransaction()
{
    this->transactionId = NULL;
    this->type = 0;
    this->wasPrepared = false;
}

////////////////////////////////////////////////////////////////////////////////
JournalTransaction::~JournalTransaction()
{
    delete this->transactionId;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* JournalTransaction::cloneDataStructure() const {
    JournalTransaction* journalTransaction = new JournalTransaction();

    // Copy the data from the base class or classes
    journalTransaction->copyDataStructure( this );

    return journalTransaction;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const JournalTransaction* srcPtr = dynamic_cast<const JournalTransaction*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "JournalTransaction::copyDataStructure - src is NULL or invalid" );
    }
    this->setTransactionId( 
        dynamic_cast<TransactionId*>( 
            srcPtr->getTransactionId()->cloneDataStructure() ) );
    this->setType( srcPtr->getType() );
    this->setWasPrepared( srcPtr->getWasPrepared() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char JournalTransaction::getDataStructureType() const {
    return JournalTransaction::ID_JOURNALTRANSACTION; 
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* JournalTransaction::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* JournalTransaction::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setTransactionId(TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
const unsigned char JournalTransaction::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char JournalTransaction::getType() {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setType(unsigned char type ) {
    this->type = type;
}

////////////////////////////////////////////////////////////////////////////////
const bool JournalTransaction::getWasPrepared() const {
    return wasPrepared;
}

////////////////////////////////////////////////////////////////////////////////
bool JournalTransaction::getWasPrepared() {
    return wasPrepared;
}

////////////////////////////////////////////////////////////////////////////////
void JournalTransaction::setWasPrepared(bool wasPrepared ) {
    this->wasPrepared = wasPrepared;
}


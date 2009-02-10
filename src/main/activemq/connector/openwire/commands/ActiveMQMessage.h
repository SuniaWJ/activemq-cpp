/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGE_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGE_H_

#include <activemq/util/Config.h>
#include <activemq/connector/openwire/commands/ActiveMQMessageBase.h>
#include <memory>

namespace activemq{
namespace connector{
namespace openwire{
namespace commands{

    class AMQCPP_API ActiveMQMessage :
        public ActiveMQMessageBase<cms::Message> {

    public:

        static const unsigned char ID_ACTIVEMQMESSAGE = 23;

    public:

        ActiveMQMessage();
        virtual ~ActiveMQMessage() {}

        virtual unsigned char getDataStructureType() const;

        /**
         * Copy the contents of the passed object into this objects
         * members, overwriting any existing data.
         * @return src - Source Object
         */
        virtual void copyDataStructure( const DataStructure* src ) {
            ActiveMQMessageBase<cms::Message>::copyDataStructure( src );
        }

        /**
         * Clone this object and return a new instance that the
         * caller now owns, this will be an exact copy of this one
         * @returns new copy of this object.
         */
        virtual ActiveMQMessage* cloneDataStructure() const {
            std::auto_ptr<ActiveMQMessage> message( new ActiveMQMessage() );
            message->copyDataStructure( this );
            return message.release();
        }

        /**
         * Returns a string containing the information for this DataStructure
         * such as its type and value of its elements.
         * @return formatted string useful for debugging.
         */
        virtual std::string toString() const{
            std::ostringstream stream;

            stream << "Begin Class = ActiveMQMessage" << std::endl;
            stream << ActiveMQMessageBase<cms::Message>::toString();
            stream << "Begin Class = ActiveMQMessage" << std::endl;

            return stream.str();
        }

        /**
         * Compares the DataStructure passed in to this one, and returns if
         * they are equivalent.  Equivalent here means that they are of the
         * same type, and that each element of the objects are the same.
         * @returns true if DataStructure's are Equal.
         */
        virtual bool equals( const DataStructure* value ) const {
            return ActiveMQMessageBase<cms::Message>::equals( value );
        }

    public:  // cms::Message

        /**
         * Clone this message exactly, returns a new instance that the
         * caller is required to delete.
         * @return new copy of this message
         */
        virtual cms::Message* clone() const {
            return dynamic_cast<cms::Message*>(
                this->cloneDataStructure() );
        }

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_ACTIVEMQMESSAGE_H_*/

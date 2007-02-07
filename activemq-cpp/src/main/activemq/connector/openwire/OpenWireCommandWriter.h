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

#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_OPENWIRECOMMANDWRITER_H_
#define _ACTIVEMQ_CONNECTOR_OPENWIRE_OPENWIRECOMMANDWRITER_H_

#include <activemq/transport/CommandWriter.h>
#include <activemq/io/OutputStream.h>
#include <activemq/io/DataOutputStream.h>
#include <activemq/transport/CommandIOException.h>
#include <activemq/transport/Command.h>
#include <activemq/connector/openwire/OpenWireFormat.h>

namespace activemq{
namespace connector{
namespace openwire{

    class OpenWireCommandWriter : public transport::CommandWriter
    {
    private:

        /**
         * Target output stream.
         */
        io::OutputStream* outputStream;

        /**
         * OpenWireFormat object we use to marshal.
         */
        OpenWireFormat* openWireFormat;

        /**
         * DataOutputStream that wraps the supplied OutputStream
         */
        io::DataOutputStream* dataOutputStream;

    public:

        /**
         * Default Constructor
         */
        OpenWireCommandWriter();

        /**
         * Constructor.
         * @param os the target output stream.
         */
        OpenWireCommandWriter( io::OutputStream* outputStream,
                               OpenWireFormat* openWireFormat );

        virtual ~OpenWireCommandWriter(void) {}

        /**
         * Sets the target output stream.
         * @param outputStream - stream to write to.
         */
        virtual void setOutputStream( io::OutputStream* outputStream ){
            this->outputStream = outputStream;
            delete dataOutputStream;
            dataOutputStream = new io::DataOutputStream( outputStream );
        }

        /**
         * Gets the target output stream.
         */
        virtual io::OutputStream* getOutputStream(void){
            return outputStream;
        }

        /**
         * Sets the target input stream.
         * @param Target Input Stream
         */
        virtual void setOpenWireFormat( OpenWireFormat* openWireFormat ){
            this->openWireFormat = openWireFormat;
        }

        /**
         * Gets the target input stream.
         * @return Target Input Stream
         */
        virtual OpenWireFormat* getOpenWireFormat(void){
            return this->openWireFormat;
        }

        /**
         * Writes a command to the given output stream.
         * @param command the command to write.
         * @param os the target stream for the write.
         * @throws CommandIOException if a problem occurs during the write.
         */
        virtual void writeCommand( transport::Command* command )
            throw ( transport::CommandIOException );

        /**
         * Writes a byte array to the output stream.
         * @param buffer a byte array
         * @param count the number of bytes in the array to write.
         * @throws IOException thrown if an error occurs.
         */
        virtual void write( const unsigned char* buffer, size_t count )
            throw( io::IOException );

        /**
         * Writes a byte to the output stream.
         * @param v The value to be written.
         * @throws IOException thrown if an error occurs.
         */
        virtual void writeByte( unsigned char v ) throw( io::IOException );

    };

}}}

#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_OPENWIRECOMMANDWRITER_H_*/

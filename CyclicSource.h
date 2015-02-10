//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __SDS_PROJECT_CYCLICSOURCE_H_
#define __SDS_PROJECT_CYCLICSOURCE_H_

#include <omnetpp.h>

/**
 * TODO - Generated class
 */

namespace sds_project {

class SourceBase : public cSimpleModule
{
    protected:
        int VMCounter;
        std::string VMName;
        simsignal_t createdSignal;
    protected:
        virtual void initialize();
        virtual void finish();
};


/**
 * Generates VM packets.
 */
class CyclicSource : public SourceBase
{
    private:
        simtime_t startTime;
        simtime_t stopTime;
        int numVMs;

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual cPacket *createPacket();
};

}; //namespace

#endif

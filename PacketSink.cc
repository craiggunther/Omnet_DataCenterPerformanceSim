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

#include "PacketSink.h"
#include <VirtualMachineImage.h>

namespace sds_project {

Define_Module(PacketSink);

void PacketSink::initialize()
{
    lifeTimeSignal = registerSignal("lifeTime");
    totalQueueingTimeSignal = registerSignal("totalQueueingTime");
    queuesVisitedSignal = registerSignal("queuesVisited");
    totalServiceTimeSignal = registerSignal("totalServiceTime");
    totalDelayTimeSignal = registerSignal("totalDelayTime");
    delaysVisitedSignal = registerSignal("delaysVisited");
    generationSignal = registerSignal("generation");
    keepJobs = par("keepJobs");
}

void PacketSink::handleMessage(cMessage *msg)
{
    VirtualMachineImage *vm = check_and_cast<VirtualMachineImage*>(msg);
    queueing::Job *job = vm->getJob();
    // gather statistics
    emit(lifeTimeSignal, simTime()- job->getCreationTime());
    emit(totalQueueingTimeSignal, job->getTotalQueueingTime());
    emit(queuesVisitedSignal, job->getQueueCount());
    emit(totalServiceTimeSignal, job->getTotalServiceTime());
    emit(totalDelayTimeSignal, job->getTotalDelayTime());
    emit(delaysVisitedSignal, job->getDelayCount());
    emit(generationSignal, job->getGeneration());

    if (!keepJobs)
        delete msg;
}

void PacketSink::finish()
{
    // TODO missing scalar statistics
}

}; //namespace

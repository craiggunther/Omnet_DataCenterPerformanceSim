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

#include <omnetpp.h>
#include <ResAllocator.h>
#include <Job.h>

namespace sds_project {

Define_Module(ResAllocator)

ResAllocator::ResAllocator(){};

ResAllocator::~ResAllocator(){};

void ResAllocator::initialize()
{
    droppedSignal = registerSignal("dropped");
    queueingTimeSignal = registerSignal("queueingTime");
    queueLengthSignal = registerSignal("queueLength");
    emit(queueLengthSignal, 0l);

    resourceAmount = par("resourceAmount");
    resourcePriority = par("resourcePriority");

    const char *resourceName = par("resourceModuleName");
    cModule *mod = getParentModule()->getModuleByPath(resourceName);
    if (!mod)
        throw cRuntimeError("Cannot find resource pool module `%s'", resourceName);
    resourcePool = check_and_cast<queueing::IResourcePool*>(mod);

}

bool ResAllocator::allocateResource(cMessage *msg){
    return resourcePool->tryToAllocate(this, resourceAmount, resourcePriority);
}

void ResAllocator::handleMessage(cMessage *msg){
    if (allocateResource(msg))
        msg->setKind(ACCEPTED);
    else
        msg->setKind(REJECTED);
    send(msg, "out");
};

}; //namespace


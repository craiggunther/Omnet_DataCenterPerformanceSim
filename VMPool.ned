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

package sds_project;
import org.omnetpp.queueing.ResourcePool;

//
// Custom ResourcePool made to acquire stats about the DataCenter utilization
//
simple VMPool extends ResourcePool
{
    @class(sds_project::VMPool);
	@signal[utilization](type="double");
    //@statistic[utilization](title="DataCenter utilization";record=vector?,timeavg,mean,max;interpolationmode=none);
}

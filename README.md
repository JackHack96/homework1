# Univr Cyberphysical Lab course - Homework 1
First homework assignement of the Cyberphysical Lab course at University of Verona, academic year 2017/2018.

Tha assignment was the following:
> Create a ROS package containing an appropriate number of nodes for doing the following tasks:  
> - A node publishes a message containing a name, an age and a degree course one time per second
> - A node select which part of the message to show with the keyboard
> - A node shows the selected part

> The node that select which part of the message to show will behave like this:  
> - If the user types `a` the message will be displayed entirely
> - If the user types `n` only the name will be displayed
> - If the user types `c` only the course will be displayed
> - If the user types `e` only the age will be displayed

It has to be said that the specifications were general and a bit ambiguos, so one can make many different solutions.

## Package structure
My solution contains three components
- The **talker**, which publish a message every second
- The **selector**, which grabs the message published by the talker and add an information
- The **listener**, which print the message according to a particular value

I've chosen to use a custom message format, which can be found in `msg/student.msg`. The message contains 4 fields:
 - `name`
 - `age`
 - `course`
 - `display`

While the first three fields are self-explaining, the fourth is used by the listener for understanding which part of the message we want to show, according to the specifications.

## How it works
The _talker_ publishes the same message every second under the topic `chatter`. The _selector_ node, which is subscribed to the `chatter` topic, receives the message and reads
from the keyboard a key. Then it stores the key value in the received message and send it to the _listener_, who proceeds to show the message's fields according to the value
of `display`.
*I know I could use a more efficient design*, but I've chosen this design because it's simple and it just works, and it was also easy to write.

## How to compile
Simply clone the repository into your ROS workspace, then run `catkin_make`.  
Assuming that your workspace is in `~/catkin_ws`:
> `git clone https://github.com/JackHack96/homework1.git`  
> `cd ~/catkin_ws && catkin_make`

## How to launch
I made a ROS launcher that you can use to automatically launch the three nodes.
> `roslaunch homework1 homework1.launch`

This command will spawn three terminals, one for `roscore`, one for the `selector` and one for the `listener` (the `talker` is not shown in his own terminal).

## Screenshots
![ROSLAUNCH](/images/roslaunch.png)
![RQT_GRAPH](/images/rosgraph.png)

---
This file is part of `homework1` and it is distributed under the terms of the GNU General Public License 3

`homework1` is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 3 for more details.

You should have received a copy of the GNU General Public License along with `homework1`. If not, see http://www.gnu.org/licenses/.

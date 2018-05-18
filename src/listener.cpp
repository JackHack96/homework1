#include "ros/ros.h"
#include "ros_homework1/student.h"

void chatterCallback(const ros_homework1::student::ConstPtr& msg)
{
  switch(msg->display){
    case 'n':
      ROS_INFO("%s", msg->name.c_str());
      break;
    case 'e':
      ROS_INFO("%d", msg->age);
      break;
    case 'c':
      ROS_INFO("%s", msg->course.c_str());
      break;
    case 'a':
      ROS_INFO("%s - %d - %s", msg->name.c_str(), msg->age, msg->course.c_str());
      break;
    default:
      break;
  }
}

int main(int argc, char **argv)
{
  ROS_INFO("Started listener");
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("selector", 1, chatterCallback);
  ros::spin();
  return 0;
}

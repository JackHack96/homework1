#include "ros/ros.h"
#include "ros_homework1/student.h"
#include <sstream>

ros_homework1::student message;

void chatterCallback(const ros_homework1::student::ConstPtr &msg)
{
  message = *msg;
  //ROS_INFO("Received message (%s - %d - %s)",message.name.c_str(),message.age,message.course.c_str());
}

int main(int argc, char **argv)
{
  ROS_INFO("Started selector");
  ros::init(argc, argv, "selector");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1, chatterCallback);
  ros::Publisher chatter_pub = n.advertise<ros_homework1::student>("selector", 1);
  char r;
  while (std::cin >> r)
  {
    ros::spinOnce();
    message.display=r;
    //ROS_INFO("Sending message (%s - %d - %s)",message.name.c_str(),message.age,message.course.c_str());
    chatter_pub.publish(message);
  }
  return 0;
}

#include "ros/ros.h"
#include "homework1/student.h"
#include <sstream>

homework1::student message;

void chatterCallback(const homework1::student::ConstPtr &msg)
{
  message = *msg;
  ROS_INFO("Received message (%s - %d - %s)",message.name.c_str(),message.age,message.course.c_str());
}

int main(int argc, char **argv)
{
  ROS_INFO("Started selector");
  ros::init(argc, argv, "selector");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1, chatterCallback);
  ros::Publisher chatter_pub = n.advertise<homework1::student>("selector", 1);
  char r;
  while (std::cin >> r)
  {
    message.display=r;
    chatter_pub.publish(message);
    ros::spinOnce();
  }
  return 0;
}

#include "ros/ros.h"
#include "ros_homework1/student.h"
#include <sstream>

int main(int argc, char **argv)
{
  ROS_INFO("Started talker");
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<ros_homework1::student>("chatter", 1);
  ros::Rate loop_rate(1);
  ros_homework1::student msg;
  while (ros::ok())
  {
    msg.name = "Matteo Iervasi";
    msg.age = 22;
    msg.course = "Informatica";
    //ROS_INFO("Publishing message (%s - %d - %s)",msg.name.c_str(),msg.age,msg.course.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

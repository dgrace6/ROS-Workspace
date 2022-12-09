#include <iostream>

#include "ros/ros.h"
#include "std_msgs/Float64.h"


int main(int argc, char **argv) {
  
	ros::init(argc, argv, "my_litte_node");
	
	ros::NodeHandle n;

	
	ros::Publisher leftPub = n.advertise<std_msgs::Float64>("left_arm_controller/command", 1000);
	ros::Publisher rightPub = n.advertise<std_msgs::Float64>("right_arm_controller/command", 1000);

	while(ros::ok()){


		char in;
		std::cout <<"Please enter a value:";
		std::cin >> in;

		std_msgs::Float64 speedMsg;

		speedMsg.data = 1.0;
	
		leftPub.publish(speedMsg);
		rightPub.publish(speedMsg);
	}

  return 0;
}

#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

std_msgs::Float64MultiArray jointTarg;
int main(int argc, char **argv)
{
   ros::init(argc, argv, "state_machine");
   ros::NodeHandle n;
   ros::Publisher pub= n.advertise<std_msgs::Float64MultiArray>("/jointpose", 1000);
	jointTarg.data.clear();
	float temp;
	int sure;
   while(ros::ok()){
   	ros::spinOnce();

   	jointTarg.data.clear();
   	for (int i=0; i<6;i++)
   	{
		printf("\nInserire i valori per il joint %d:\t", i);
   			std::cin >> temp;
   			temp=temp*3.14/180;
   			jointTarg.data.push_back(temp);
	}
	printf("Inserire 1 se si vuole confermare, 0 per scegliere nuovi angoli");
	std::cin >> sure;
	if (sure == 1)
	{
		pub.publish(jointTarg);
	}

   }
   return 0;
}

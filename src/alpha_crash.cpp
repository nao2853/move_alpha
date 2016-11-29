#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

//パブリッシャーの定義（メッセージ送信）
ros::Publisher velocity_publisher;
//サブスクライバーの定義（メッセージ受信）
ros::Subscriber pose_subscriber;

//vel_msgをgeometry_msgsのTwist型として定義
geometry_msgs::Twist vel_msg;

const double PI = 3.1415926;

//関数のプロトタイプ宣言
void move(double distance);
void rotate(double relative_angle);
void writeCircle(double radius, double turn_angle);


int main(int argc, char **argv)
{
	ros::init(argc, argv, "alpha_crash");
	ros::NodeHandle n;

	velocity_publisher = n.advertise<geometry_msgs::Twist>("/icart_mini/cmd_vel", 10);

	//pose_subscriber = n.subscribe("/nav_msgs/Odometry", 10, poseCallback);

	ROS_INFO("\n*********** start icart mini sim ***********");
	while(1)
	{
		vel_msg.angular.z = 1.0;
		vel_msg.linear.x = 1.0;
		velocity_publisher.publish(vel_msg);
	}
}


/*void poseCallback(nav_msgs::Pose::ConstPtr & pose_message)
{
	icart_mini_pose.x = pose_message -> x;
	icart_mini_pose.y = pose_message -> y;
}
*/
/*
void move(double distance)
{
	double pose0_x = 0, pose0_y = 0;
	double pose1_x = 0, pose1_y = 0;
	double current_distance = 0;

	ros::Rate loop_rate(1000);
	
	do{
		ros::spinOnce();
		pose0_x = icart_mini_pose.x;
		pose0_y = icart_mini_pose.y;
	}while(pose0_x == 0 || pose0_y == 0);
	
	vel_msg.linear.x = 2;
	do{
		velocity_publisher.publish(vel_msg);
		ros::spinOnce();
		pose1_x = icart_mini_pose.x;
		pose1_x = icart_mini_pose.y;
		
		if((pose1_x - pose0_x) == 0)
			current_distance = pose1_y - pose0_y;
		else if((pose1_y - pose0_y) == 0)
			current_distance = pose1_x - pose0_x;
		else
			current_distance = sqrt(pow(pose1_x - pose0_x, 2) + pow(pose1_y - pose0_y, 2));

		loop_rate.sleep();
	}while(fabs(current_distance) < distance);

	vel_msg.linear.x = 0;
	velocity_publisher.publish(vel_msg);
}
*/
/*void writeCircle(double radius, double target_angle)
{
	ros::Rate loop_rate(1000);
	double current_angle = 0.0;

	vel_msg.angular.z = 1.0;
	vel_msg.linear.x = fabs(radius * vel_msg.angular.z);
	
	target_angle += */

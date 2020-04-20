#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <eigen3/Eigen/Dense>
#include <Eigen/Dense>
#include <math.h>
#include <iostream>
// Callback of timer
// Broadcaster transform from A to B and B to C
void broadcastTF(const ros::TimerEvent& timer_event)
{
  static tf::TransformBroadcaster br;
  Eigen::Quaterniond q_C_B(std::sqrt(3)/2,0,0,0.5);
  //Eigen::Quaterniond q_C_B(1,0,0,0);
  Eigen::Vector3d v_C_B(1,0,0);

  tf::Transform  tf_C_B;
  tf::Quaternion tf_q_C_B(q_C_B.x(),q_C_B.y(),q_C_B.z(),q_C_B.w());
  tf::Vector3    tf_v_C_B(v_C_B(0),v_C_B(1),v_C_B(2));

  tf_C_B.setOrigin(tf_v_C_B);
  tf_C_B.setRotation(tf_q_C_B);

  br.sendTransform(tf::StampedTransform(tf_C_B,ros::Time::now(),"C","B"));


  Eigen::Quaterniond q_B_A(cos(90.0*M_PI/180.0/2),0,0,sin(90*M_PI/180.0/2));
  //Eigen::Quaterniond q_C_B(1,0,0,0);
  Eigen::Vector3d v_B_A(1,0,0);

  tf::Transform  tf_B_A;
  tf::Quaternion tf_q_B_A(q_B_A.x(),q_B_A.y(),q_B_A.z(),q_B_A.w());
  tf::Vector3    tf_v_B_A(v_B_A(0),v_B_A(1),v_B_A(2));

  tf_B_A.setOrigin(tf_v_B_A);
  tf_B_A.setRotation(tf_q_B_A);
  br.sendTransform(tf::StampedTransform(tf_B_A,ros::Time::now(),"B","A"));
  tf::Transform tf_C_A = tf_C_B*tf_B_A;
  br.sendTransform(tf::StampedTransform(tf_C_A,ros::Time::now(),"C","A1"));
  tf::Vector3 tf_v_C_A = tf_C_A.getOrigin();
  std::cout << "x:" <<tf_v_C_A[0] <<" y:"<< tf_v_C_A[1]<<" z:"<< tf_v_C_A[2]<<std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "answer_1");
  ros::NodeHandle nh;
  // Create timer with 2.0 Hz
  ros::Timer timer = nh.createTimer(ros::Duration(0.5), broadcastTF);
  while (ros::ok()){ros::spinOnce();}
  return 0;
}

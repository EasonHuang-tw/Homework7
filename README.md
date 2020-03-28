![image](https://github.com/Robotics-Aerial-Robots/Homework2/blob/master/photo/LOGO%20%E4%B8%AD%E8%8B%B1%E6%96%87%E6%A9%AB.png)
# Homework4
#### Questions:
1. Please draw the following plot using Eigen::Quaterniond(w x y z) and tf::Quaternion(x y z w) in rviz.	
2. Be aware of the directions of arrows. Pointing from  A to B implies the transformation from A to B.	
3. In the first figure, vectors BA and CA are the inputs to generate output vector BC.	
4. In the second figure, vector AB is rotated by 90 degree about the z axis and vector BC is rotated by 60 degree about the z axis, and generate the output vector AC.	

<img src="https://github.com/Robotics-Aerial-Robots/Homework/blob/master/photo/week_3_2.png" width="40%" height="40%">	
<img src="https://github.com/Robotics-Aerial-Robots/Homework/blob/master/photo/week_3_1.png" width="40%" height="20%">	

### Instruction

```
	roscore
	rosrun HW4  tf_cf1 or tf_cf2 .... tf_cf4
	rosrun rviz 
```

#### Reminders:
* Please check the code in the src for reference.	
* Eigen::Quaterniond(w x y z) and tf::Quaternion(x y z w)

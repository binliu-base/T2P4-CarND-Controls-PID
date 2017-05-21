# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

# Overview
The goals / steps of this project are the following:  

* Complete PID controller (steer angle) in C++.
* Tune PID controller parameters 
* Test PID controller on the simulator and make sure the vehicle is able to drive successfully around the track.

### Final Result
[Here] is the video that demonstrates the vehicle controlled by the PID controller successfully drives around the track in the simulator. 

## PID Components 

PID is compose of three types controllers. 

P - proportional controller direct reduce next cross track error. While only using P controller is not enough for effective car driving, the car will overshoot and drive off track very quickly.

D - derivative controller is use to reduce the oscillation problems in P controller.

I - integral controller is use to eliminate system bias problem in PD controller. 

The input of PID is Cross Track Error that specifies how far away the car is away from the intended driving route (center of the road), The output is the appropriate steering angle that controls the car driving.

The equation of steering angle compuation as below:

steering_angle = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte 

tau_p * cte : Proportional Controller  
tau_d * diff_cte: Differential Controller  
tau_i * int_cte:  Integral Controller  


## PID hyperparameter tuning
Final hyperparameters for submission was tuned manually. 

1.  First, I started by setting all PID coefficients to a value of 0. With this configuration, the car would drive completely straight with no error response.

2. Then increase the P term (tau_p) until the output of the loop oscillates,
(with I and D set to 0 coefficient). Note, if tau_p was set too low, car was not able to steer back to the centerline. While when the value was too high, oscillations will increased and the car will run out of track finally.

2. Then increase D term (tau_d), if required, until the loop is acceptably quick to reach its reference after a load disturbance. 


2. Finally, increase I term (tau_i) until any offset is corrected in sufficient time for the process. Note, tau_i can be set to in the case, because system bias is 0 in the simulator. 

Final parameters were: P = 0.1 I = 0.001 D = 1.5

## Discussion

This is a fun project, Which surprised me how simple and powerful a one line equation can help us smoothly drive the car in the simulator. This is an initial version of PID controller, 
We may add automated PID parameters tuning and Speed PID controller features in the real world.






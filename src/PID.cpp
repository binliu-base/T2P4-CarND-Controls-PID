#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_i, double Ki_i, double Kd_i) {
    // initialize coefficients and errors
    Kp = Kp_i;
    Ki = Ki_i;
    Kd = Kd_i;

    // initialize errors
    p_error = 0.;
    d_error = 0.;
    i_error = 0.;
    prev_cte = 0.;
}

void PID::UpdateError(double cte) {

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  prev_cte = cte;

}



double PID::TotalError() {
    // calculates the output of the PID
    return -Kp * p_error - Kd * d_error - Ki * i_error;    
}


#include <iostream>
#include <stdlib.h>
#include "PID.h"

using namespace std;

PID::PID() {
}

PID::~PID() {
}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	cte_prev = 0;
	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte, double dt) {
	p_error = Kp * cte;
	d_error = Kd * (cte - cte_prev) / dt;
	i_error += Ki * cte * dt;

	cte_prev = cte;
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}

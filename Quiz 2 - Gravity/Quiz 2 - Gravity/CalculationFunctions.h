#ifndef CALCULATIONFUNCTIONS_H
#define CALCULATIONFUNCTIONS_H
#include "Constants.h"
#include "ForwardDec.h"
#include <iostream>

double calcHeight(double height, double time) //calculates the height at a given time.
{
	double x = gravity*time*time / 2;
	height = height + x;
	if (height >= 0)
		return height;
	else return 0;
}

double calcTime(double height) //calculates the time it takes for the height to reach 0.
{
	return sqrt(-2 * height / gravity);
}

double calcVelocity(double height, double time) //calculates velocity at a given instant in time.
{
	if (time<=calcTime(height)) return -gravity*time;
	else return 0;
}




#endif
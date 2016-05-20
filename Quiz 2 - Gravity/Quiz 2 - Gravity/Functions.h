#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include "Constants.h"

using namespace std;
double startHeight() //gets the initial drop height from the user
{	
	int x{ 0 };
	while (x <= 0)
	{
		cout << "Please enter the height of the building you are dropping the ball off: " << endl;
		cin >> x;
		if (x <= 0)
		{
			cout << "Please enter a height greater than zero." << endl;
		}
	}
	return x;
}

double calcHeight(double height, double time) //calculates the height at a given time.
{
	double x = gravity*time*time/2;
	height = height + x;
	if (height>=0)
	return height;
	else return 0;
}

void drop(double height) //counts up from a given time, returning the time at 1 second intervals.
{
	for (int x=0; height>0; x++)
	{
		height = calcHeight(height, x);
		cout << "The height at " << x << " seconds is: " << height << endl;
	}
	return;
}

int userSelect()
{
	int x{ 0 };
	cout << "Please choose one of the following options\n"
		 << "1. Show the height as a function of time at 1 second intervals\n"
		 << "2. Show the height at a specific time\n"
		 << "3. Calculate how long it will take the ball to hit the ground\n";
	cin >> x;
	while (x != 1 & x != 2 & x != 3) //if the user doesnt enter a valid option, ask them again.
	{
		cout << "That wasn't one of the options, please choose again." << endl;
		cin >> x;
	}
	return x;
}

void selection(int selection, double height)
{
	if (selection == 1)
	{
		drop(height);
		return;
	}
	return;
}
#endif
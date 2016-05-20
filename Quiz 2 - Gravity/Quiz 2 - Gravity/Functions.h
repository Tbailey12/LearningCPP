#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include "Constants.h"
#include "ForwardDec.h"

using namespace std;
double startHeight() //gets the initial drop height from the user
{	
	int x{ 0 };
	cout << "Please enter the height of the building you are dropping the ball off: " << endl;
	while (x <= 0)
	{
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
	double h{ 1 };
	for (int x=0; h>0; x++)
	{
		h = calcHeight(height, x);
		cout << "The height at " << x << " seconds is: " << h << "m" << endl;
	}
	return;
}

int userSelect()
{
	int x{ 0 };
	cout << "Please choose one of the following options:\n"
		<< "1. Show the height as a function of time at 1 second intervals\n"
		<< "2. Show the height at a specific time\n"
		<< "3. Calculate how long it will take the ball to hit the ground\n"
		<< "4. Calculate the velocity at a specific time\n"
		<< "5. Change the drop height\n"
		<< "6. Quit the calculator\n";
	cin >> x;
	while (x != 1 & x != 2 & x != 3 & x != 4 & x != 5 & x != 6) //if the user doesnt enter a valid option, ask them again.
	{
		cout << "That wasn't one of the options, please choose again." << endl;
		cin >> x;
	}
	return x;
}

bool selection(int selection, double height) //decides what to do based on the integer in selection
{
	if (selection == 1)
	{
		drop(height);
		wait();
	}
	if (selection == 2)
	{
		double time;
		cout << "Please enter the time in seconds: " << endl;
		cin >> time;
		cout << "The height at " << time << " seconds = " << calcHeight(height, time) << "m" << endl;
		wait();
	}
	if (selection == 6)
	{
		cout << "Thanks for using the gravity calculator!" << endl;
		return false;
	}
	return true;
}
void wait() 
{
	cin.clear(); // reset any error flags
	cin.ignore(LONG_MAX, '\n'); //ignore anything in the input buffer
	cout << "Press any key to continue...";
	cin.get(); //get one more char from the user.
}
#endif
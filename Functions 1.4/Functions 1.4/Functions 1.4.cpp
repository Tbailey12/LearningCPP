#include "stdafx.h"
#include <iostream>
#include "operations.h"

using std::cout;
using std::cin;

int main()
{
	//reads two inputs from the user and then uses add() to add the two values and their sum
	int x(0); //direct initialization (preferred)
	int y = 0;
	cout << "Please enter the first value: ";
	cin >> x;
	cout << "Please enter the second value: ";
	cin >>  y;
	cout << "The two values you entered were: " << x << " & " << y << std::endl;

	cout << "The sum of these values is: " << add(x,y) << std::endl << std::endl;

	//reads another number then doubles the number using a function
	cout << "Enter another number to be doubled: " << std::endl;
	cin >> x;
	cout << "Double " << x << " = " << doubleNumber(x) << std::endl;

	//reads another number and then multiplies the number using a seperate file
	cout << "Enter another number to be multiplied with " << x << std::endl;
	cin >> y;
	cout << x << " multiplied by " << y << " = " << multiply(x, y) << std::endl;

	return 0;
}

#include "stdafx.h"
#include <iostream>

using namespace std;

char operator1;										//global to go between functions

double getDouble()
{
	cout << "Enter a double value: " << endl;
	double x;
	cin >> x;
	return x;
}

char getOperator(bool x)
{
	if (x == true) 
	{
		cout << "That was an incorrect entry, please try again.\nEnter one of the following: +, -, *, or /: " << endl;
		cin.clear();								//clears error/bad flags on cin
		cin.ignore(cin.rdbuf()->in_avail(), '\n');	//ignores the exact number of characters in the input buffer
		cin >> operator1;
		return operator1;
	}
	else
	{
		cout << "Enter one of the following: +, -, *, or /: " << endl;
		cin >> operator1;
		return operator1;
	}
}

double doOperation(double entry1, char operator1, double entry2)
{
	while (true)								//keep doing this till there's a valid input
	{
		if (operator1 == '+')
			return entry1 + entry2;
		else if (operator1 == '-')
			return entry1 - entry2;
		else if (operator1 == '*')
			return entry1 * entry2;
		else if (operator1 == '/')
			return entry1 / entry2;
		else operator1=getOperator(true);			//if no valid input, ask for another one
	}
}

int main()
{
	double entry1(getDouble());
	double entry2(getDouble());

	getOperator(false);

	double result(doOperation(entry1, operator1, entry2));	//calculate the result, operator1 is global
	cout << entry1 << " " << operator1 << " " << entry2 << " = " << result << endl;

	cin.ignore(LONG_MAX, '\n');
    return 0;
}
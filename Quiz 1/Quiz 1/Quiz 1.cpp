#include "stdafx.h"
#include <iostream>
#include "functionDec.h"

using std::cout;
using std::cin;

int main()
{
	cout << "Please enter a number " << std::endl;
	int number1 = readNumber();
	cout << "Please enter a second number " << std::endl;
	int number2 = readNumber();
	writeAnswer(number1, number2);

    return 0;
}


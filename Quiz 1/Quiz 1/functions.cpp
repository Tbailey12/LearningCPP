#include "stdafx.h"
#include <iostream>

using namespace std;

int readNumber()
{
	int x;
	cin >> x;
	return x;
}

void writeAnswer(int x, int y)
{
	cout << x << " + " << y << " = " << x + y << std::endl;
}
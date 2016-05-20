#include "stdafx.h"
#include <iostream>
#include "Constants.h"
#include "Functions.h"
using namespace std;

int main()
{
	cout << "Welcome to the gravity calculator." << endl;
	double height = startHeight(); //gets the drop height from the user
	bool run{ true };
	while (run==true)
	{
		run = selection(userSelect(), height);
	}
    return 0;
}


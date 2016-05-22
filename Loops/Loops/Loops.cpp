#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int counter{ 0 };

	//while loop
	while (counter < 10)
	{
		++counter;
		cout << "While " << counter << endl;
	}

	counter = 0;
	//Do while loop
	do													// It always does this once
	{
		++counter;
		cout << "Do while " << counter << endl;
	} while (counter < 10);
	
	//For Loop
	for (counter = 0; counter < 10; ++counter)
	{
		cout << "For " << counter+1 << endl;
	}


    return 0;
}


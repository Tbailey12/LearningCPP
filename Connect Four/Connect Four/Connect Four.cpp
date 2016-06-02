#include "stdafx.h"
#include <iostream>
#include <string>
#include "forwardDecs.h"
#include "windows.h"



int main()
{
	string array[rows][columns]{ };
	welcome();
	string player1{ getPlayer(1) };
	string player2{ getPlayer(2) };
	cout << "\n" << player1 << " X vs. " << player2 << " O \n" << endl;
	displayArray(array);
	playGame();
    return 0;
}


#include "stdafx.h"
#include <iostream>
#include <string>
#include "forwardDecs.h"
#include "windows.h"


int main()
{
	string gameArray[rows][columns];
	setArray(gameArray);
	//welcome();
	string player1{ getPlayer(1) };
	string player2{ getPlayer(2) };
	cout << "\n" << player1 << " X vs. " << player2 << " O \n" << endl;
	displayArray(gameArray);
	playGame(gameArray, player1, player2);
    return 0;
}


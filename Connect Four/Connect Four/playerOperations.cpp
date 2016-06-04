#include "stdafx.h"
#include <iostream>
#include "forwardDecs.h"

using namespace std;
// requests the player to enter a unique name, which is returned by the function
string getPlayer(int playerID) 
{
	cout << "Player " << playerID << " please enter your name: " << endl;
	string playerName{};
	getline(cin, playerName);
	return playerName;
}

//Gets the row the player wishes to drop their token into.
int getPlayerInput(string gameArray[][columns], int playerID)
{
	int playerInput;
	while (1) {
		cin >> playerInput;
		if (checkValidInput(gameArray,playerInput)) {
			return playerInput-1;
			break;
		}
		cin.ignore(INT_MAX, '\n');
		cin.clear();
		cout << "That was not a valid input, please enter the row in which you wish to place the token, row 1 is on the far left \n";
	}
}

//checks whether the column entered is within range and also that it doesn't already contain a token
bool checkValidInput(string gameArray[][columns],int input)
{
	if (input <= columns && input > 0 && gameArray[0][input-1] == space)
	{
		return true;
	}
	else return false;
}
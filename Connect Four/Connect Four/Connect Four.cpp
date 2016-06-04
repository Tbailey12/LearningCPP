#include "stdafx.h"
#include <iostream>
#include <string>
#include "forwardDecs.h"
#include "windows.h"


int main()
{
	string gameArray[rows][columns];
	welcome();
	string player1{ getPlayer(1) };
	string player2{ getPlayer(2) };
	j_playAgain:
	setArray(gameArray);
	cout << "\n" << player1 << " vs. " << player2 << " \n" << endl;
	Sleep(1000);
	displayArray(gameArray);
	playGame(gameArray, player1, player2);
	cout << "Would you like to play again? Type 1 for yes or 0 for no: ";
	int playAgain;
	cin >> playAgain;
	if (playAgain)
	{
		system("cls");
		cout << "This time it's your turn to go first " << player2 << endl;
		swap(player1, player2);
		goto j_playAgain;
	}
    return 0;
}


#include "stdafx.h"
#include <iostream>
#include "forwardDecs.h"
#include <string>

using namespace std;

int playGame(string gameArray[][columns], string player1, string player2) {
	int turn = 1;
		while (1) {												//Loops while the game is being played
			while (turn == 1)									//player 1's turn
			{
				cout << player1 << ", please enter while column you would like to drop the token into: " << endl;
				updateArray(gameArray, 1, getPlayerInput(gameArray, 1));	//puts the players token into the column entered by the player
				simulateArray(gameArray);						//simulates tokens falling the the bottom of each column
				displayArray(gameArray);						//displays the updated array on the screen
				turn = 2;
				break;
			}
			while (turn == 2)									//player 2's turn
			{
				cout << player2 << ", please enter while column you would like to drop the token into: " << endl;
				updateArray(gameArray, 2, getPlayerInput(gameArray, 2));	//puts the players token into the column entered by the player
				simulateArray(gameArray);						//simulates tokens falling the the bottom of each column
				displayArray(gameArray);						//displays the updated array on the screen
				turn = 1;
				break;
			}
		}
		return 1;
}
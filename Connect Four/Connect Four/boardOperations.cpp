#include "stdafx.h"
#include <iostream>
#include "forwardDecs.h"
#include <utility>
#include <Windows.h>

//fills the array with spaces to make formatting consistent
void setArray(string gameArray[][columns])
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; j++)
		{
			gameArray[i][j] = space;
		}
	}
}

//check 1 space in the direction for the given token (space, X, O)
bool checkSouth(string gameArray[][columns], string check, int row, int column)
{
	if (gameArray[row+1][column] == check)
	{
		return true;
	}
	else return false;
}

//simulates the token falling into the grid
void simulateArray(string gameArray[][columns])
{
	for (int i = 0; i < rows-1; ++i)
	{
		for (int j = 0; j < columns; j++)
		{
			if (checkSouth(gameArray, space, i, j))
			{
				gameArray[i][j].swap(gameArray[i+1][j]);
			}
		}
	}
}

//places a token in row 0 in the desired column
void updateArray(string gameArray[][columns], int playerID, int column)
{
	if (playerID == 1)
	{
		gameArray[0][column] = token1;
	}
	else if (playerID == 2)
	{
		gameArray[0][column] = token2;
	}
}
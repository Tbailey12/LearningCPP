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

bool checkConnect4(string gameArray[][columns], int playerID)
{
	if (playerID == 1) 
	{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{	
					//checking south
					if (i < rows - 3 && gameArray[i][j] == token1) {
						int count = 1;
						for (int k = 0; k < 3; ++k) {
							if (checkSouth(gameArray, token1, i+k, j))
							{
								count++;
								continue;
							}
							else break;
						}
						if (count == 4) {
							return true;
						}
					}
					//checking east
					if (j < columns-3 && gameArray[i][j] == token1) {
						int count = 1;
						for (int k = 0; k < 3; ++k) {
							if (checkEast(gameArray, token1, i, j+k))
							{
								count++;
								continue;
							}
							else break;
						}
						if (count == 4) {
							return true;
						}
					}
					//checking south east
					if (i < rows-3 && j < columns-3 && gameArray[i][j] == token1) {
						int count = 1;
						for (int k = 0; k < 3; ++k) {
							if (checkSouthEast(gameArray, token1, i + k, j + k))
							{
								count++;
								continue;
							}
							else break;
						}
						if (count == 4) {
							return true;
						}
					}
					//checking south west
					if (i < rows-3 && j > 2 && gameArray[i][j] == token1) {
						int count = 1;
						for (int k = 0; k < 3; ++k) {
							if (checkSouthWest(gameArray, token1, i + k, j - k))
							{
								count++;
								continue;
							}
							else break;
						}
						if (count == 4) {
							return true;
						}
					}
					
				}
			}
			return false;
	}
	if (playerID == 2)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				//checking south
				if (i < rows - 3 && gameArray[i][j] == token2) {
					int count = 1;
					for (int k = 0; k < 3; ++k) {
						if (checkSouth(gameArray, token2, i + k, j))
						{
							count++;
							continue;
						}
						else break;
					}
					if (count == 4) {
						return true;
					}
				}
				//checking east
				if (j < columns - 3 && gameArray[i][j] == token2) {
					int count = 1;
					for (int k = 0; k < 3; ++k) {
						if (checkEast(gameArray, token2, i, j + k))
						{
							count++;
							continue;
						}
						else break;
					}
					if (count == 4) {
						return true;
					}
				}
				//checking south east
				if (i < rows - 3 && j < columns - 3 && gameArray[i][j] == token2) {
					int count = 1;
					for (int k = 0; k < 3; ++k) {
						if (checkSouthEast(gameArray, token2, i + k, j + k))
						{
							count++;
							continue;
						}
						else break;
					}
					if (count == 4) {
						return true;
					}
				}
				//checking south west
				if (i < rows - 3 && j > 2 && gameArray[i][j] == token2) {
					int count = 1;
					for (int k = 0; k < 3; ++k) {
						if (checkSouthWest(gameArray, token2, i + k, j - k))
						{
							count++;
							continue;
						}
						else break;
					}
					if (count == 4) {
						return true;
					}
				}

			}
		}
		return false;
	}

}

//check 1 space in the direction for the given token (space, X, O)
bool checkSouth(string gameArray[][columns], string check, int row, int column)
{
	if (gameArray[row+1][column] == check && row < rows-1)
	{
		return true;
	}
	else return false;
}
bool checkEast(string gameArray[][columns], string check, int row, int column)
{
	if (gameArray[row][column+1] == check && column < columns-1)
	{
		return true;
	}
	else return false;
}
bool checkSouthWest(string gameArray[][columns], string check, int row, int column)
{
	if (gameArray[row + 1][column - 1] == check && column > 0 && row < rows)
	{
		return true;
	}
	else return false;
}
bool checkSouthEast(string gameArray[][columns], string check, int row, int column)
{
	if (gameArray[row + 1][column + 1] == check && column < columns && row < rows)
	{
		return true;
	}
	else return false;
}
//simulates the token falling into the grid
void simulateArray(string gameArray[][columns])
{
	displayArray(gameArray);
	for (int i = 0; i < rows-1; ++i)
	{
		Sleep(100);
		for (int j = 0; j < columns; j++)
		{
			if (checkSouth(gameArray, space, i, j))
			{
				gameArray[i][j].swap(gameArray[i+1][j]);
			}
		}
		displayArray(gameArray);
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
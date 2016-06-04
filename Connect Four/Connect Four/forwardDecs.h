// All function forward declarations & constants are stored here
#ifndef FORWARDDECS_H
#define FORWARDDECS_H
#include <string>
using namespace std;

//Constants
const int rows{ 6 };
const int columns{ 7 };
const string space{ " " };
const string token1{ "X" };
const string token2{ "O" };

//Display
void welcome();
void displayArray(string gameArray[][columns]);

//Player
string getPlayer(int PlayerID);
int getPlayerInput(string gameArray[][columns], int playerID);
bool checkValidInput(string gameArray[][columns], int input);

//Board
void setArray(string gameArray[][columns]);
bool checkConnect4(string gameArray[][columns], int playerID);
bool checkSouth(string gameArray[][columns], string check, int row, int column);
bool checkEast(string gameArray[][columns], string check, int row, int column);
bool checkSouthWest(string gameArray[][columns], string check, int row, int column);
bool checkSouthEast(string gameArray[][columns], string check, int row, int column);
void simulateArray(string gameArray[][columns]);
void updateArray(string gameArray[][columns],int playerID, int column);


//Misc
int playGame(string gameArray[][columns], string player1, string player2);



#endif
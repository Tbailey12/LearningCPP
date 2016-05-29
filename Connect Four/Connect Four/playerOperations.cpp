#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string getPlayer(int playerID) {
	cout << "Player " << playerID << " please enter your name: " << endl;
	string playerName{};
	getline(cin, playerName);
	return playerName;
}
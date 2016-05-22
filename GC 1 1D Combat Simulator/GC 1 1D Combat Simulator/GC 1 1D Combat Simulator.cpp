#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//global variables
int numberOfHumans, numberOfSkeletons;
const int humanHP{ 100 };
const int humanDMG{ 70 };
const int skeletonHP{ 50 };
const int skeletonDMG{ 100 };
const int delay{ 1000 };

//Random number generator function - remember srand in main
float rand(float min, float max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	//evenly distribute random number across our range
	return static_cast<int>(rand()*fraction*(max - min + 1) + min);
}



//function makes two groups fight and changes gloabl human and skeleton variables
void fight(int humans, int skeletons) 
{
	double skeleTempHP{ skeletonHP };
	double humanTempHP{ humanHP };
	bool turn{ true };											// controls whose turn it is to hit true = human
	cout << "Beginning combat" << endl;
	Sleep(delay);
	cout << "~~ Fighting Noises ~~" << endl;
	Sleep(delay);

	while (skeletons > 0 & humans > 0)
	{
		double humanHit = rand(0, humanDMG);
		double skeletonHit = skeletonDMG - rand(0, skeletonDMG);

		if (turn == true)										//human attacks
		{
			Sleep(1);
			if (skeletonHit >= skeleTempHP)						//hit kills
			{
				--skeletons;
				skeleTempHP = skeletonHP;
				turn = false;
			}
			else if (skeletonHit < skeleTempHP)					//hit doesn't kill
			{
				skeleTempHP -= skeletonHit;
				turn = false;
			}
		}
		if (turn == false)										//skeleton attacks
		{
			Sleep(1);
			if (humanHit >= humanTempHP)						//hit kills
			{
				--humans;
				humanTempHP = humanHP;
				turn = true;
			}
			else if (humanHit < humanTempHP)					//hit doesn't kill
			{
				humanTempHP -= humanHit;
				turn = true;
			}
		}
		numberOfHumans = humans;
		numberOfSkeletons = skeletons;
	}
	

}


int main()
{	
	srand(static_cast<unsigned int>(time(0)));					//set initial seed value to system clock
	cout << "Welcome to the skeleton killing simulator.\nPlease enter the number of humans: " << endl;
	cin >> numberOfHumans;
	cout << "Please enter the number of skeletons: " << endl;
	cin >> numberOfSkeletons;
	int initHumans{ numberOfHumans }, initSkeletons{ numberOfSkeletons };

	
	fight(numberOfHumans, numberOfSkeletons);
	
	if (numberOfHumans > numberOfSkeletons) cout << "Humans win. ";
	else if (numberOfSkeletons > numberOfHumans) cout << "Skeletons win. ";

	cout << "There were " << initHumans - numberOfHumans << " human casualties, and "
		<< initSkeletons - numberOfSkeletons << " skeletons were slain" << endl;
	
    return 0;
}


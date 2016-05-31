#include "stdafx.h"
#include <iostream>
#include <random>

std::random_device rd;				//Use a hardware entropy source if available
std::mt19937 mersenne(rd());		//initialize the mersenne twister alogithm with a random seed

int main()
{
	

	for (int i = 0; i < 20; ++i)
	{
		std::cout << mersenne() << "\n";
	}

    return 0;
}


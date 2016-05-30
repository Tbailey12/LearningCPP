#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

enum class Type
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct Monster 
{
	Type type;
	string name;
	int health;

};

string printType(Type type)						//returns the type of monster from enum Type as a string
{
	switch (type)
	{
	case Type::OGRE:
		return "an Ogre";
		break;
	case Type::DRAGON:
		return "a Dragon";
		break;
	case Type::ORC:
		return "an Orc";
		break;
	case Type::GIANT_SPIDER:
		return "a Giant Spider";
		break;
	case Type::SLIME:
		return "a Slime";
		break;
	default:
		return "Not a valid type";
		break;
	}
}

void printMonster(Monster monster) 
{
	cout << monster.name << " is " << printType(monster.type) << " and has " << monster.health << " HP\n";
}

int main()
{
	Monster m1{ Type::OGRE,"Torg",145 };
	Monster m2{Type::GIANT_SPIDER,"Steve",23};

	printMonster(m1);
	printMonster(m2);

	cout << "Select a monster type: \n"
			"0 = Ogre \n"
			"1 = Dragon \n"
			"2 = Orc \n"
			"3 = Giant Spider \n"
			"4 = Slime \n";

	int entry;								//get an input from the user and change it to a an enum Type	
	cin >> entry;
	cout << printType(static_cast<Type>(entry)) << "\n";

    return 0;
}


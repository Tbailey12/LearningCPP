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
		return " ";
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
    return 0;
}


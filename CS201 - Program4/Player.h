#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Player
{
public:
	Player();
	Player(string newName, string newMark);
	string getMark();
	string getName();
	void setName(string newName);
	void setMark(string newMark);
private:
	string name;
	string mark;
};
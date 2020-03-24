#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Tile
{
public:
	Tile();
	string getMark();
	void setMark(string newMark);
	bool isAvailable();
private:
	bool available;
	string playerMark;
};
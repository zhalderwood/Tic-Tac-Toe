#include <iostream>
#include <string>
#include "Tile.h"

using namespace std;

Tile::Tile()
{
	available = true;
	playerMark = " ";
};
string Tile::getMark() { return playerMark; }
void Tile::setMark(string newMark) 
{ 
	playerMark = newMark; 
	available = false;
}
bool Tile::isAvailable() { return available; }
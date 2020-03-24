#include <string>
#include "Player.h"

using namespace std;

Player::Player()
{
	name = " ";
	mark = " ";
}

Player::Player(string newName, string newMark)
{
	name = newName;
	mark = newMark;
}

string Player::getName() { return name; }
string Player::getMark() { return mark; }
void Player::setName(string newName) { name = newName; }
void Player::setMark(string newMark) { mark = newMark; }
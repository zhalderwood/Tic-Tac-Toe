// Zachary Halderwood
// zjuvz6@mail.umkc.edu
// 3/19/2020
// CS201R - Program 4

#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Tile.h"

using namespace std;

int main() 
{
	Board* board = new Board();
	board->newGame();
	return 0;
}
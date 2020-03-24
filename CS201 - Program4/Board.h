#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "Tile.h"


using namespace std;


class Board: public Tile
{
public:
	Board();
	void splashScreen();
	void definePlayers();
	void printBoard();
	void saveBoard();
	bool victoryCheck(string currentMark);
	void resetBoard();
	void gameCore();
	void newGame();
private:	
	Player *player1;
	Player *player2;
	Tile* boardSpace[3][3];
};
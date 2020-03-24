#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Board.h"

using namespace std;

Board::Board()
// Default constructor sets up blank players and blank board
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->boardSpace[i][j] = new Tile();
		}
	}
	this->player1 = new Player();
	this->player2 = new Player();
}

void Board::splashScreen()
// ASCII is fun, although tedious
{
	cout << "[]================================================================================================[]" << endl;
	cout << "||                                                                                                ||" << endl;
	cout << "||  //////////////  ///  //////     /////////  ////////  //////    /////////  ////////  //////    ||" << endl;
	cout << "||         ///     ///  //            ///     //    //  //           ///     //    //  //         ||" << endl;
	cout << "||        ///     ///  //            ///     ////////  //           ///     //    //  ////        ||" << endl;
	cout << "||       ///     ///  //            ///     //    //  //           ///     //    //  //           ||" << endl;
	cout << "||      ///     ///  //////        ///     //    //  //////       ///     ////////  ////////////  ||" << endl;
	cout << "||                                                                                                ||" << endl;
	cout << "[]================================================================================================[]" << endl;
	cout << "                                                                     developed by Zachary Halderwood" << endl;
}

void Board::definePlayers()
// Takes input for player names and creates Player objects
{
	string tempName;
	string tempMark = "X";
	for (int i = 1; i < 3; i++)
	{
		cout << "Please enter a name for player " << i << "." << endl;
		getline(cin, tempName);
		cout << endl << tempName << "'s board mark will be " << tempMark << endl;
		if (i == 1) 
		{ 
			player1->setName(tempName);
			player1->setMark(tempMark);
			tempMark = "O";
		}
		else
		{
			player2->setName(tempName);
			player2->setMark(tempMark);
		}
		cout << endl;
	}

}

void Board::printBoard()
/*
Prints board in the format shown:
 _____________
| X || X || X |
|___||___||___|
| O || O || X |
|___||___||___|
| X || O || O |
|___||___||___|
*/
{
	cout << " _____________" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "| " << boardSpace[i][0]->getMark() << " || " << boardSpace[i][1]->getMark() << " || " << boardSpace[i][2]->getMark() << " |" << endl;
		cout << "|___||___||___|" << endl;
	}
}

void Board::saveBoard()
// writes game board to a file
{
	ofstream fout; 
	fout.open("ticTacToe.txt");
	fout << " _____________" << endl;
	for (int i = 0; i < 3; i++)
	{
		fout << "| " << boardSpace[i][0]->getMark() << " || " << boardSpace[i][1]->getMark() << " || " << boardSpace[i][2]->getMark() << " |" << endl;
		fout << "|___||___||___|" << endl;
	}
	fout.close();
}

bool Board::victoryCheck(string currentMark)
// checks for victory conditions in all rows, columns, and diagonals
// returns bool value depending on what it finds
{
	for (int i = 0; i < 3; i++)
	{
		if ((currentMark == boardSpace[0][i]->getMark()) && (currentMark == boardSpace[1][i]->getMark()) && (currentMark == boardSpace[2][i]->getMark()))
		// check columns for victory
		{
			return true;
		}
		else if ((currentMark == boardSpace[i][0]->getMark()) && (currentMark == boardSpace[i][1]->getMark()) && (currentMark == boardSpace[i][2]->getMark()))
		// check rows for victory
		{
			return true;
		}
	}
	if ((currentMark == boardSpace[0][0]->getMark()) && (currentMark == boardSpace[1][1]->getMark()) && (currentMark == boardSpace[2][2]->getMark()))
	// Check for forward diagonal victory
		{
			return true;
		}
	else if ((currentMark == boardSpace[0][2]->getMark()) && (currentMark == boardSpace[1][1]->getMark()) && (currentMark == boardSpace[2][0]->getMark()))
	// check for reverse diagonal victory
		{
			return true;
		}
	else
	{
		return false;
	}
}

void Board::resetBoard()
// clears the board for a new match
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardSpace[i][j]->Tile::Tile();
		}
	}
}

void Board::gameCore()
// main game logic
{
	cout << "Let's get playing." << endl;
	int row, col;
	int spacesAvailable = 9;
	bool gameWon = false;
	string currentName = player1->getName();
	string currentMark = player1->getMark();
	while (!gameWon)
	// continues until a winner is declared or there is a tie
	{
		printBoard();
		bool turnOngoing = true;
		while (turnOngoing)
		{
			cout << currentName << ", choose to spot place your mark." << endl;
			cout << "Row: ";
			cin >> row;
			row--;
			cout << "Column: ";
			cin >> col;
			col--;
			cout << endl;
			if ((0 <= row < 3) && (0 <= col < 3))
			{
				if (this->boardSpace[row][col]->isAvailable())
				{
					boardSpace[row][col]->setMark(currentMark);
					turnOngoing = false;
					spacesAvailable--;
				}
				else
				{
					cout << "That space has already been marked. Try again." << endl;
				}
			}
			else
			{
				cout << "Invalid entry. Row and column numbers should 1, 2, or 3." << endl;
			}

		}
		
		gameWon = victoryCheck(currentMark);
		if (!gameWon && (spacesAvailable > 0))
		// switch active players
		{
			if (currentMark == "X")
			{
				currentName = player2->getName();
				currentMark = player2->getMark();

			}
			else
			{
				currentName = player1->getName();
				currentMark = player1->getMark();
			}
		}
		else if (!gameWon && (spacesAvailable == 0))
		{
			printBoard();
			cout << "We have a tie: no winners in this match." << endl;
			gameWon = true;
		}
		else
		{
			printBoard();
			cout << currentName << " wins!" << endl;
			gameWon = true;
		}
	}
}

void Board::newGame()
{
	splashScreen();
	definePlayers();
	bool playing = true;
	bool choiceMade;
	char choice;
	while (playing)
	{
		gameCore();
		saveBoard();
		choiceMade = false;
		while (!choiceMade)
		{
			cout << "Would you like to play again? (Y/N)" << endl;
			cin >> choice;
			choice = toupper(choice);
			if (choice == 'Y')
			{
				cout << "(S)ame players or (D)ifferent players?" << endl;
				cin >> choice;
				choice = toupper(choice);
				if (choice == 'S')
				{
					choiceMade = true;
					resetBoard();
					cin.clear();
					cin.ignore();
					gameCore();
				}
				else if (choice == 'D')
				{
					choiceMade = true;
					resetBoard();
					cin.clear();
					cin.ignore();
					definePlayers();
					gameCore();
				}
			}
			else if (choice == 'N')
			{
				choiceMade = true;
				playing = false;
			}
		}
	}
	cout << "Thanks for playing!";
}
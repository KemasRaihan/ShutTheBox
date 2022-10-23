#include "Board.h"


Board::Board(int numberOfTiles) : numberOfTiles(numberOfTiles)
{
	tiles = new Tile*[numberOfTiles];

	// Assigned each tile their corresponding number
	for (int i = 0; i < numberOfTiles; ++i) tiles[i] = new Tile(i);

}

Board::~Board()
{
	for (int i = 0; i < numberOfTiles; ++i)
	{
		delete tiles[i];
	}
	tiles = nullptr;
}

//---------------------------------------------
//| Dice Amount | Tiles That Must Be Available
//---------------------------------------------
//       2                   2
//       3                 1, 3
//       4                1, 3, 4
//       5              1, 2, 3, 4, 5
//       6              1, 2, 4, 5, 6
//       7              

bool Board::availableTiles(const int diceAmount)
{
	switch (diceAmount)
	{
	case 2: if (tiles[1]->isShut()) return false;

	case 3: if (tiles[0]->isShut() && tiles[2]->isShut()) return false;

	case 4: if (tiles[0]->isShut() && tiles[3]->isShut()) return false;

	case 5: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[4]->isShut()) return false;

	case 6: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[5]->isShut()) return false;

	case 7: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[2]->isShut() && tiles[6]->isShut()) return false;

	case 8: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[2]->isShut() && tiles[7]->isShut()) return false;

	case 9: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[2]->isShut() && tiles[3]->isShut() && tiles[8]->isShut()) return false;

	case 10: if (tiles[0]->isShut() && tiles[1]->isShut() && tiles[2]->isShut() && tiles[3]->isShut()) return false;

	case 11: if (tiles[1]->isShut() && tiles[2]->isShut() && tiles[3]->isShut() && tiles[4]->isShut()) return false;

	case 12: if (tiles[2]->isShut() && tiles[3]->isShut() && tiles[4]->isShut()) return false;
	}

	return true;
}

void Board::chooseTilesToFlip(const int diceAmount)
{
	int tileNumberChosen = 0, tileAmount = 0;

	// allow user to choose tiles until the sum of the tile numbers
	// they have chosen is equal to total dice amount
	while (tileAmount < diceAmount)
	{
		tileNumberChosen = Game::choose();

		if (flipChosenTile(tileNumberChosen)) // only allow user to flip tiles that are still open
		{
			tileAmount += tileNumberChosen;
		}

		if (tileAmount > diceAmount)
		{
			std::cout << "Invalid tile. Please try again.";
			tiles[tileNumberChosen - 1]->flip(); // reset tile that has been flipped
			tileAmount -= tileNumberChosen;
		}
	}
}

bool Board::flipChosenTile(const int number)
{
	if (number <= 0 || number > numberOfTiles)
	{
		std::cout << "Number must be between 1 and 9" << std::endl;
		return false;
	}
	else if (tiles[number - 1]->isShut())
	{
		std::cout << "Tile already shut" << std::endl;
		return false;
	}
	tiles[number - 1]->flip();
	return true;
}

void Board::showAvailableTiles()
{
	for (int i = 0; i < numberOfTiles; ++i)
	{
		if (!tiles[i]->isShut())
		{
			std::cout << "Tile " << i + 1 << std::endl;
		}
	}
}



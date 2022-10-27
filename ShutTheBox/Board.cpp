#include "Board.h"



Board::Board() : numberOfTiles(9)
{
	tiles = new Tile*[9];

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
//| Dice Sum | Different Combinations For Sum
//---------------------------------------------
//       2                   2
//       3                3, 2 & 1
//       4                4, 3 & 1
//       5             5, 4 & 1, 3 & 2
//       6             6, 5 & 1, 4 & 2
//       7          7, 6 & 1, 5 & 2, 4 & 3
//       8          8, 7 & 1, 6 & 2, 5 & 3
//       9       9, 8 & 1, 7 & 2, 6 & 3, 5 & 4
//       10       9 & 1, 8 & 2, 7 & 3, 6 & 4
//       11           9 & 2, 8 & 3, 6 & 5
//       12              9 & 3, 8 & 4

bool Board::checkForAvailableTiles(const int& diceAmount) const
{
	bool tile2IsShut = tiles[1]->isShut();
	bool tile3IsShut = tiles[2]->isShut();
	bool tile4IsShut = tiles[3]->isShut();
	bool tile5IsShut = tiles[4]->isShut();
	bool tile6IsShut = tiles[5]->isShut();
	bool tile7IsShut = tiles[6]->isShut();
	bool tile8IsShut = tiles[7]->isShut();
	bool tile9IsShut = tiles[8]->isShut();

	bool tile1or2IsShut = (tiles[0]->isShut() || tiles[1]->isShut());
	bool tile1or3IsShut = (tiles[0]->isShut() || tiles[2]->isShut());
	bool tile1or4IsShut = (tiles[0]->isShut() || tiles[3]->isShut());
	bool tile1or5IsShut = (tiles[0]->isShut() || tiles[4]->isShut());
	bool tile1or6IsShut = (tiles[0]->isShut() || tiles[5]->isShut());
	bool tile1or7IsShut = (tiles[0]->isShut() || tiles[6]->isShut());
	bool tile1or8IsShut = (tiles[0]->isShut() || tiles[7]->isShut());
	bool tile1or9IsShut = (tiles[0]->isShut() || tiles[8]->isShut());

	bool tile2or3IsShut = (tiles[1]->isShut() || tiles[2]->isShut());
	bool tile2or4IsShut = (tiles[1]->isShut() || tiles[3]->isShut());
	bool tile2or5IsShut = (tiles[1]->isShut() || tiles[4]->isShut());
	bool tile2or6IsShut = (tiles[1]->isShut() || tiles[5]->isShut());
	bool tile2or7IsShut = (tiles[1]->isShut() || tiles[6]->isShut());
	bool tile2or8IsShut = (tiles[1]->isShut() || tiles[7]->isShut());
	bool tile2or9IsShut = (tiles[1]->isShut() || tiles[8]->isShut());

	bool tile3or4IsShut = (tiles[2]->isShut() || tiles[3]->isShut());
	bool tile3or5IsShut = (tiles[2]->isShut() || tiles[4]->isShut());
	bool tile3or6IsShut = (tiles[2]->isShut() || tiles[5]->isShut());
	bool tile3or7IsShut = (tiles[2]->isShut() || tiles[6]->isShut());
	bool tile3or8IsShut = (tiles[2]->isShut() || tiles[7]->isShut());
	bool tile3or9IsShut = (tiles[2]->isShut() || tiles[8]->isShut());

	bool tile4or5IsShut = (tiles[3]->isShut() || tiles[4]->isShut());
	bool tile4or6IsShut = (tiles[3]->isShut() || tiles[5]->isShut());
	bool tile4or7IsShut = (tiles[3]->isShut() || tiles[6]->isShut());
	bool tile4or8IsShut = (tiles[3]->isShut() || tiles[7]->isShut());

	bool tile5or6IsShut = (tiles[4]->isShut() || tiles[5]->isShut());
	bool tile5or7IsShut = (tiles[4]->isShut() || tiles[6]->isShut());


	switch (diceAmount)
	{
	case 2: if (tile2IsShut) return false;

	case 3: if (tile3IsShut && tile1or2IsShut) return false;

	case 4: if(tile4IsShut && tile1or3IsShut) return false;

	case 5: if (tile5IsShut && tile1or4IsShut && tile2or3IsShut) return false;

	case 6: if (tile6IsShut && tile1or5IsShut && tile2or4IsShut) return false;

	case 7: if (tile7IsShut && tile1or7IsShut && tile2or5IsShut && tile3or4IsShut) return false;

	case 8: if (tile8IsShut && tile1or7IsShut && tile2or6IsShut && tile3or5IsShut) return false;

	case 9: if (tile9IsShut && tile1or8IsShut && tile2or7IsShut && tile3or6IsShut && tile4or5IsShut) return false;

	case 10: if (tile1or9IsShut && tile2or7IsShut && tile3or6IsShut && tile4or5IsShut) return false;

	case 11: if (tile2or9IsShut && tile3or8IsShut && tile4or7IsShut && tile5or6IsShut) return false;

	case 12: if (tile3or9IsShut && tile4or8IsShut && tile5or7IsShut) return false;
	}

	return true;
}

bool Board::flipChosenTile(const int& number)
{
	if (number < 1 || number > numberOfTiles)
	{
		std::cout << "Tile doesn't exist" << std::endl;
		return false;
	}
	else if (tiles[number - 1]->isShut())
	{
		std::cout << "Tile already shut" << std::endl;
		return false;
	}
	else
	{
		tiles[number - 1]->flip();
		return true;
	}
}


void Board::resetTiles(int* tilesToReset, const int& numberOfTilesToReset)
{
	for (int i = 0; i < numberOfTilesToReset; ++i)
	{
		tiles[tilesToReset[i]-1]->flip();
	}
}

void Board::showAvailableTiles() const
{
	for (int i = 0; i < numberOfTiles; ++i)
	{
		if (!tiles[i]->isShut())
		{
			std::cout << "Tile " << i + 1 << std::endl;
		}
	}
}




#pragma once
#include "Game.h"
#include "Tile.h"
#include <iostream>

class Board
{
public:
	Board();
	~Board();

	bool checkForAvailableTiles(const int& diceAmount) const; // check to see if there are available tiles to choose
	bool flipChosenTile(const int& number);
	inline int getNumberOfTiles() const;
	inline Tile** getTiles() const;
	void resetTiles(int* tilesToReset, const int& numberOfTilesToReset);
	void showAvailableTiles() const; // show tiles that are still open

private:
	Tile** tiles;
	int numberOfTiles;
};


inline int Board::getNumberOfTiles() const { return numberOfTiles; }
inline Tile** Board::getTiles() const { return tiles; }




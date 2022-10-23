#pragma once
#include "Game.h"
#include <iostream>

class Board
{
	struct Tile
	{
		Tile(int number) : number(number) { shut = false; }

		inline void flip(); // player flips tile to either open or close it
		inline bool isShut() const; // to check whether has been opened or closed

		int number;
		bool shut;
	};

public:
	Board(int numberOfTiles);
	~Board();

	bool availableTiles(const int diceAmount); // check to see if there are available tiles to choose
	void chooseTilesToFlip(const int diceAmount);
	bool flipChosenTile(const int number);
	void showAvailableTiles(); // show tiles that are still open

	inline int getNumberOfTiles() const;

private:
	Tile** tiles;
	int numberOfTiles;

};

inline void Board::Tile::flip() { shut = !shut; }
inline bool Board::Tile::isShut() const { return shut; }

inline int Board::getNumberOfTiles() const{ return numberOfTiles;  }
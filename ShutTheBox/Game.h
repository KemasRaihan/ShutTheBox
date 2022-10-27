#pragma once
#include "Board.h"
#include "Dice.h"
#include <iostream>

struct Player
{
	int score;
	Player() : score(0) {}
};

class Game
{
public:
	Game();
	~Game();

	void calculateFinalScore(); // add all remaining tile numbers to the final score
	inline int chooseTile(); // get user to choose a tile number to flip
	void chooseTilesToFlip(const int& sumNeeded);
	inline void displayFinalScore() const; // display the score or print 'Congratulations, you have shut the box!' if score = 0
	void play(); // play 'Shut The Box' game
	void showTilesChosen(const int* tilesChosen, const int& numberOfTilesChosen); // show tiles that have been chosen by the user during each throw


private:
	class Board* board;
	Player* player;
};

inline int Game::chooseTile()
{
	int number;
	std::cin >> number;
	return number;
}











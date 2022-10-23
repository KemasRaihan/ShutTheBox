#pragma once
#include "Board.h"
#include "Dice.h"
#include <iostream>

struct Player
{
	int score;
	Player(int score) : score(score) {}
};

class Game
{
public:
	Game();
	~Game();

	void play(); // play 'Shut The Box' game

	inline void addScore(const int amount); // add all tile numbers to player's score
	static inline int choose(); // get user to choose a tile number to flip

private:
	Board* board;
	Player* player;
};


inline void Game::addScore(const int amount)
{
	player->score += amount;
}

int Game::choose()
{
	int number;
	std::cin >> number;
	return number;
}






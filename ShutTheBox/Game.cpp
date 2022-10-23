#include "Game.h"

Game::Game()
{
	board = new Board(9);
	player = new Player(0);
}

Game::~Game()
{
	delete board;
	board = nullptr;

	delete player;
	player = nullptr;
}

void Game::play()
{
	int diceAmount = 0; 

	do {
		int diceAmount = Dice::roll() + Dice::roll();

		std::cout << "Dice Amount : " << diceAmount << std::endl;

		board->showAvailableTiles();

		std::cout << "Choose which tiles to shut:" << std::endl;

		board->chooseTilesToFlip(diceAmount);

	} while (board->availableTiles(diceAmount));
}







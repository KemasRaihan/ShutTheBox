#include "Game.h"

const int maxSize = 4;

Game::Game()
{
	board = new Board();
	player = new Player();
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
	int diceAmount; 
	bool keepPlaying;

	while (keepPlaying=true)
	{
		board->showAvailableTiles();

		diceAmount = Dice::roll() + Dice::roll();

		std::cout << "Dice amount: " << diceAmount << std::endl;

		if (!board->checkForAvailableTiles(diceAmount)) break; // if there are no available tiles left to choose, end the game

		std::cout << "Choose which tiles to shut: ";

		chooseTilesToFlip(diceAmount);
	}

	calculateFinalScore();
	displayFinalScore();
}

void Game::calculateFinalScore()
{
	for (int i = 0; i < board->getNumberOfTiles(); ++i)
	{
		if (!board->getTiles()[i]->isShut()) // if tile is not shut, add number to the score
		{
			player->score += board->getTiles()[i]->getNumber();
		}
	}
}

void Game::displayFinalScore() const
{
	if (player->score == 0)
	{
		std::cout << "Congratulations, you have shut the box!" << std::endl;
	}
	else
	{
		std::cout << "Final score is " << player->score << std::endl;
	}
}


void Game::chooseTilesToFlip(const int& sumNeeded)
{
	int tileChosen;
	int tileSum = 0;
	int numberOfTilesChosen = 0;
	int* tilesChosen = (int*)malloc(sizeof(int) * maxSize);

	// allow user to choose tiles until the sum of the tile numbers
	// they have chosen is equal to total dice amount
	while (tileSum != sumNeeded)
	{
		tileChosen = Game::chooseTile();

		// if tile has not been shut
		if (board->flipChosenTile(tileChosen))
		{
			tileSum += tileChosen;
			tilesChosen[numberOfTilesChosen] = tileChosen;
			numberOfTilesChosen++;
			showTilesChosen(tilesChosen, numberOfTilesChosen);
		}
		
		// reset variables if tileSum exceeds dice total
		if (tileSum > sumNeeded)
		{
			board->resetTiles(tilesChosen, numberOfTilesChosen);

			tileSum = 0;
			numberOfTilesChosen = 0;

			free(tilesChosen);
			tilesChosen = nullptr;

			tilesChosen = (int*)malloc(sizeof(int) * maxSize);

			std::cout << "Invalid tiles chosen please try again." << std::endl;
		}

	}

	free(tilesChosen);
	tilesChosen = nullptr;
}

void Game::showTilesChosen(const int* tilesChosen, const int& numberOfTilesChosen)
{
	std::cout << "Tiles chosen [";
	for (int i = 0; i < numberOfTilesChosen; ++i)
	{
		std::cout << tilesChosen[i] << ",";
	}
	std::cout << "]" << std::endl;
}









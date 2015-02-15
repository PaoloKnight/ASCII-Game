#pragma once

#include <string>
#include <vector>
#include "Snake.h"

enum class GameState { MENU, PLAY, EXIT };

class MainGame {
public:
	MainGame();
	~MainGame();
	void run();

private:
	void loadMap(const std::string& fileName, Snake& snake);
	void gameLoop();
	void print();
	void handleInput(char input, Snake& snake);

	std::vector <std::string> _mapData;
	Snake _snake;
	GameState _gameState;
	int _score;
};


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
	void inputPhase(Snake& snake);
	void processInput(Snake& snake, int targetX, int targetY);
	char getTile(int x, int y) { return _mapData[y][x]; }
	void setTile(int x, int y, char newTile) { _mapData[y][x] = newTile; }

	std::vector <std::string> _mapData;
	Snake _snake;
	GameState _gameState;
	int _score;
};


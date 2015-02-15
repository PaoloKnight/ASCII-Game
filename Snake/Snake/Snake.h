#pragma once

#include <vector>
#include <string>

class Snake {
public:
	Snake();
	~Snake();
					   
	void drawSnake();
	// Getters 
	int getSnakeSize() { return _snakeSize; }
	int getFruitsEaten() { return _fruitsEaten; }
	void getPosition(int& x, int& y) { x = _x; y = _y; }
	int getX() { return _x; }
	int getY() { return _y; }

	// Setters
	void incrementSnakeSize() { _snakeSize++; }
	void incrementFruitsEaten() { _fruitsEaten++; }
	void setSnakePosition(int x, int y) { _x = x; _y = y; }

private:
	int _fruitsEaten;
	int _snakeSize;
	int _x;
	int _y;
	std::vector <std::string> _snake;
};


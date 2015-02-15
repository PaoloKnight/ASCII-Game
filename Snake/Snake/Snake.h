#pragma once

class Snake {
public:
	Snake();
	~Snake();

	void drawSnake();
	// Getters 
	int getSnakeSize() { return _snakeSize; }
	int getFruitsEaten() { return _fruitsEaten; }
	int getSnake_x() { return _x; }
	int getSnake_y() { return _y; }

	// Setters
	void incrementSnakeSize() { _snakeSize++; }
	void incrementFruitsEaten() { _fruitsEaten++; }
	void setSnakePosition(int x, int y) { _x = x; _y = y; }

private:
	int _fruitsEaten;
	int _snakeSize;
	int _x;
	int _y;
};


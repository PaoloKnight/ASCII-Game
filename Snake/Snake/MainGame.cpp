#include "MainGame.h"

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <conio.h>

// Implementa Header e cpp Errori  - Uso win.h per sleep

MainGame::MainGame() {
	loadMap("level.txt", _snake);
	_score = 0;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame() {
}


void MainGame::loadMap(const std::string& fileName, Snake& snake) {
	std::ifstream file(fileName);

	// Se fallisce usciamo dal caricamento e dal gioco
	if (file.fail()) {
		perror(fileName.c_str());
		system("pause");
		exit(1);
	}

	// Costruzione del vettore che contiene la Mappa
	std::string line;
	while (std::getline(file, line)) {
		_mapData.push_back(line);
	}

	file.close();

	// Ottengo la posizione iniziale
	for (int i = 0; i < _mapData.size(); i++) {
		for (int j = 0; j < _mapData[i].size(); j++) {
			switch (_mapData[i][j]) {
				case '@':
					_snake.setSnakePosition(i, j);
					break;
			}
		}
	}
}

void MainGame::gameLoop() {
	char input;
	while (_gameState != GameState::EXIT) {
		print();
		inputPhase(_snake);
		system("cls");
	}
}

void MainGame::run() {
	gameLoop();
}

void MainGame::print() {
	// Pulisce lo schermo e stampa la mappa
	std::cout << std::endl;
	for (int i = 0; i < _mapData.size(); i++) {
		std::cout << _mapData[i] << std::endl;
	}
	std::cout << std::endl;
	Sleep(500);
}

void MainGame::inputPhase(Snake& snake) {
	char input;
	input = _getch();
	switch (input) {
		case 'W':
		case 'w':
			processInput(snake, snake.getX(), snake.getY() - 1);
			break;
		case 'S':
		case 's':
			processInput(snake, snake.getX(), snake.getY() + 1);
			break;
		case 'A':
		case 'a':
			processInput(snake, snake.getX() - 1, snake.getY());
			break;
		case 'D':
		case 'd':
			processInput(snake, snake.getX() + 1, snake.getY());
			break;
		default:
			std::cout << "Invalid Move" << std::endl;
			break;
	}
}

void MainGame::processInput(Snake& snake, int targetX, int targetY) {
	int snakeX;
	int snakeY;
	snake.getPosition(snakeX, snakeY);
	
	char moveTile = getTile(targetX, targetY);
	switch (moveTile) {
	case '.':
		// In questo caso ci si puo' muovere
		setTile(snake.getX(), snake.getY(), '.');
		snake.setSnakePosition(targetX, targetY);
		setTile(targetX, targetY, '@');
		break;
	case '#':
		// Se si tratta di un cancelletto non si muove
		break;
	default:
		// Se nella mappa è presente qualche altro blocco non riconosciuto non fa niente
		break;
	}
}
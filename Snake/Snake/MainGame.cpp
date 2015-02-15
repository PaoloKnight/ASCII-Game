#include "MainGame.h"

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <conio.h>

// Implementa Header e cpp Errori  - Uso win.h per sleep

MainGame::MainGame() {
	loadMap("C:\\Users\\Paolo\\Desktop\\Snake\\Snake\\level.txt", _snake);
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
		input = _getch();
		handleInput(input, _snake);
		Sleep(200);
	}
}

void MainGame::run() {
	gameLoop();
}

void MainGame::print() {
	// Pulisce lo schermo e stampa la mappa
	system("cls");
	std::cout << std::endl;
	for (int i = 0; i < _mapData.size(); i++) {
		std::cout << _mapData[i] << std::endl;
	}
	std::cout << std::endl;
}

void MainGame::handleInput(char input, Snake& snake) {
	switch (input) {
		case 'w':
			break;
		case 's':
			// HANDLE THE CODA
			break;
		case 'a':
			break;
		case 'd':
			break;
		default:
			std::cout << "Input non valido!" << std::endl;
			break;
	}
}



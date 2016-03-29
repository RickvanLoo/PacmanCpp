/*
 * Game.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: rick
 */

#include "../include/Game.h"

Game::Game(std::vector<std::vector<int>> map) : UI(map) {
	// TODO Auto-generated constructor stub

}

void Game::Reset(){
	std::cout << "Call for Game::Reset()" << std::endl;

	Movable Pacman(1,1,PACMAN,RIGHT);


	this->setScore(0);

	this->setLives(3);

	// Render the scene
	std::vector<GameObjectStruct> objects = {Pacman.getStruct()};
	this->update(objects);
}


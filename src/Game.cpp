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
	GameObjectStruct pacman;
		pacman.x = 1;
		pacman.y = 1;
		pacman.type = PACMAN;
		pacman.dir = UP;

		this->setScore(0); /* <-- Put your code in the setter */

				// Set the amount of lives
		this->setLives(3); /* <-- Put your code in the setter */

				// Render the scene
		std::vector<GameObjectStruct> objects = {pacman};
		this->update(objects); /* <-- Put your code in the update function (e.g. game->getStructs()) */
}


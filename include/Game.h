/*
 * Game.h
 *
 *  Created on: Mar 28, 2016
 *      Author: rick
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "UI.h"
#include "Pacman.h"


class Game: private UI {
public:
	Game(std::vector<std::vector<int>> map);
	void Reset();
	void Start();
	void Tick();
private:
	void UpdateScreen();
	std::vector<GameObjectStruct> ObjectStructList;
	std::vector<GameObject> Walls;
	Pacman PlayerObject;
	SDL_Event e;
	void EventHandler(SDL_Event);
	void CreateWallObjects();
};

#endif /* SRC_GAME_H_ */

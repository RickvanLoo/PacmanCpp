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
#include <map>
#include <tuple>
#include <algorithm>


class Game: private UI {
public:
	Game(std::vector<std::vector<int>> map);
	void Reset();
	void Start();
	void Tick();
	void RemoveObject(GameObject*);
	void IncScore(int);
private:
	void UpdateScreen();
	std::vector<GameObjectStruct> ObjectStructList;
	std::map<std::tuple<int,int>, GameObject*> GameObjects;
	Pacman PlayerObject;
	SDL_Event e;
	void SDLEventHandler(SDL_Event);
	void CreateObjects();
};

#endif /* SRC_GAME_H_ */

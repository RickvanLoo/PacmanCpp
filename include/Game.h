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
#include "Ghost.h"
#include <map>
#include <tuple>
#include <iterator>
#include <algorithm>


class Game: private UI {
public:
	Game(std::vector<std::vector<int>> map);
	void Reset();
	void Start();
	void Tick();
	void RemoveObject(GameObject*);
	void IncScore(int);
	void DecLives(int);
private:
	void UpdateScreen();
	std::vector<GameObjectStruct> ObjectStructList;
	std::map<std::tuple<int,int>, GameObject*> GameObjects;
	Pacman PlayerObject;
	std::vector<Ghost*> Ghosts;
	SDL_Event e;
	void SDLEventHandler(SDL_Event);
	void CreateObjects();
};

#endif /* SRC_GAME_H_ */

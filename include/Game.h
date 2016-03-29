/*
 * Game.h
 *
 *  Created on: Mar 28, 2016
 *      Author: rick
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "UI.h"
#include "Movable.h"


class Game: private UI {
public:
	Game(std::vector<std::vector<int>> map);
	void Reset();
};

#endif /* SRC_GAME_H_ */

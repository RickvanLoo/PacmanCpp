/*
 * Pacman.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef INCLUDE_PACMAN_H_
#define INCLUDE_PACMAN_H_

#include "Movable.h"
#include <map>
#include <tuple>

class Pacman: public Movable {
public:
	Pacman();
	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();
	void Reset();
	void Tick(std::map<std::tuple<int,int>, GameObject*>);
private:
	void DetectCollision(std::map<std::tuple<int,int>, GameObject*>);
	void ResolveCollision(GameObject*);
	int TickCount;
	bool Moving;
	Direction CurrentDir;
};

#endif /* INCLUDE_PACMAN_H_ */

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
	void Reset();
	void Tick(std::map<std::tuple<int,int>, GameObject*>);
private:
	void DetectDotCollision(std::map<std::tuple<int,int>, GameObject*>);
	void DetectWallCollision(std::map<std::tuple<int,int>, GameObject*>);
	void DetectGhostCollision(std::map<std::tuple<int,int>, GameObject*>);
	int TickCount;

};

#endif /* INCLUDE_PACMAN_H_ */

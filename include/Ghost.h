/*
 * Ghost.h
 *
 *  Created on: Mar 31, 2016
 *      Author: rick
 */

#ifndef INCLUDE_GHOST_H_
#define INCLUDE_GHOST_H_

#include "Movable.h"
#include <stdlib.h>

class Ghost: public Movable {
public:
	Ghost(int,int,Type,Direction);
	void Tick(std::map<std::tuple<int,int>, GameObject*> GameObjects);
	void Reset();
	void Scare();
	void deScare();
private:
	void RandomDirection();
	void DetectCollision(std::map<std::tuple<int,int>, GameObject*>);
	void ResolveCollision(GameObject*);
	int DefaultX, DefaultY;
	int TickCount;
	Type DefaultType;

};

#endif /* INCLUDE_GHOST_H_ */

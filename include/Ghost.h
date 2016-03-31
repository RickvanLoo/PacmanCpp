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
private:
	void RandomDirection();
	int TickCount;
	void DetectCollision(std::map<std::tuple<int,int>, GameObject*>);
	void ResolveCollision(GameObject*);

};

#endif /* INCLUDE_GHOST_H_ */

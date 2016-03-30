/*
 * Movable.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef SRC_MOVABLE_H_
#define SRC_MOVABLE_H_


#include "GameObject.h"
#include <map>
#include <tuple>

class Movable: public GameObject {
public:
	Movable(int, int, Type, Direction);
	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();
	void Move(int, int);
	void setMoving(bool);
	bool getMoving();
	void setDir(Direction);
	Direction getDir();
protected:
	void DetectCollision(std::map<std::tuple<int,int>, GameObject*>);
	void ResolveCollision(GameObject*);
private:
	bool Moving;
	Direction CurrentDir;
};

#endif /* SRC_MOVABLE_H_ */

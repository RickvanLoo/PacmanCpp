/*
 * Movable.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef SRC_MOVABLE_H_
#define SRC_MOVABLE_H_


#include "GameObject.h"


class Movable: public GameObject {
public:
	Movable(int, int, Type, Direction);
	void Move(int, int);
	bool CollideWith(GameObject*);
};

#endif /* SRC_MOVABLE_H_ */

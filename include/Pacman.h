/*
 * Pacman.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef INCLUDE_PACMAN_H_
#define INCLUDE_PACMAN_H_

#include "Movable.h"

class Pacman: public Movable {
public:
	Pacman();
	void GoLeft();
	void GoRight();
	void GoUp();
	void GoDown();
	void Reset();
};

#endif /* INCLUDE_PACMAN_H_ */

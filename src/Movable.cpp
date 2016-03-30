/*
 * Movable.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/Movable.h"
#include <iostream>

Movable::Movable(int x, int y, Type type, Direction dir) : GameObject(x,y,type,dir) {
	// TODO Auto-generated constructor stub

}

void Movable::Move(int x, int y){
	GameObjectStruct Info = this->getStruct();

	//Portal
	if (Info.x + x < 0){
		x = x + 28;
	}
	if (Info.x + x > 28){
		x = x - 29;
	}

	this->setLocation(Info.x + x, Info.y + y);
}




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
	this->setLocation(Info.x + x, Info.y + y);
}

bool Movable::CollideWith(GameObject Object){
	GameObjectStruct Self = this->getStruct();
	GameObjectStruct Other = Object.getStruct();

	if ((Self.x == Other.x) && (Self.y == Other.y)){
		return true;
	}else{
		return false;
	}
}


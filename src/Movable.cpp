/*
 * Movable.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/Movable.h"
#include "../include/Game.h"

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

void Movable::GoUp(){
	this->setDirection(UP);
	this->CurrentDir = UP;
	this->Moving = true;
}

void Movable::GoDown(){
	this->setDirection(DOWN);
	this->CurrentDir = DOWN;
	this->Moving = true;
}

void Movable::GoLeft(){
	this->setDirection(LEFT);
	this->CurrentDir = LEFT;
	this->Moving = true;
}

void Movable::GoRight(){
	this->setDirection(RIGHT);
	this->CurrentDir = RIGHT;
	this->Moving = true;
}




void Movable::ResolveCollision(GameObject *other){
	//Wall
	if (other->getPassable() == false){
		this->Moving = false;
	}

	//Dot
	if (other->getEdible() == true ){
		this->getPtr()->IncScore(other->getScore());
		this->getPtr()->RemoveObject(other);
	}


}

void Movable::DetectCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){
	GameObjectStruct Self = this->getStruct();

	std::tuple<int,int> CheckLocation;

	//Check Location relative to Current Direction
	switch(this->CurrentDir){
	case UP:
		CheckLocation = std::make_tuple(Self.x, Self.y - 1);
		break;
	case DOWN:
		CheckLocation = std::make_tuple(Self.x, Self.y + 1);
		break;
	case LEFT:
		CheckLocation = std::make_tuple(Self.x - 1, Self.y);
		break;
	case RIGHT:
		CheckLocation = std::make_tuple(Self.x + 1, Self.y);
		break;
	}

	if(ObjectMap.count(CheckLocation) > 0){
		//Collision Detected
		this->ResolveCollision(ObjectMap[CheckLocation]);

	}
}

void Movable::setMoving(bool input){
	this->Moving = input;
}

bool Movable::getMoving(){
	return this->Moving;
}

void Movable::setDir(Direction dir){
	this->CurrentDir = dir;
}

Direction Movable::getDir(){
	return this->CurrentDir;
}

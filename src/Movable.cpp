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

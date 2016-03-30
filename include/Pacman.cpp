/*
 * Pacman.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/Pacman.h"
#include <iostream>

Pacman::Pacman() : Movable(1,1,PACMAN,RIGHT) {
	// TODO Auto-generated constructor stub
	this->setLethal(false);
	this->setKillable(true);
	this->TickCount = 0;
	this->Moving = false;
}

void Pacman::GoUp(){
	this->setDirection(UP);
	this->CurrentDir = UP;
	this->Moving = true;
}

void Pacman::GoDown(){
	this->setDirection(DOWN);
	this->CurrentDir = DOWN;
	this->Moving = true;
}

void Pacman::GoLeft(){
	this->setDirection(LEFT);
	this->CurrentDir = LEFT;
	this->Moving = true;
}

void Pacman::GoRight(){
	this->setDirection(RIGHT);
	this->CurrentDir = RIGHT;
	this->Moving = true;
}

void Pacman::Tick(std::map<std::tuple<int,int>, GameObject*> GameObjects){
	//Check for Collisions
	this->DetectCollision(GameObjects);


	//Not Moving
	if(Moving == false){
		return;
	}

	this->TickCount++;

	if (TickCount > 2){
		switch(this->CurrentDir){
		case UP:
			this->Move(0,-1);
			this->TickCount = 0;
			break;
		case DOWN:
			this->Move(0,1);
			this->TickCount = 0;
			break;
		case LEFT:
			this->Move(-1,0);
			this->TickCount = 0;
			break;
		case RIGHT:
			this->Move(1,0);
			this->TickCount = 0;
			break;
		}
	}

}

void Pacman::ResolveCollision(GameObject *other){
	if (other->getPassable() == false){
		this->Moving = false;
	}
}

void Pacman::DetectCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){
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


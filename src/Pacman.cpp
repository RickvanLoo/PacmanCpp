/*
 * Pacman.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/Pacman.h"
#include "../include/Game.h"
#include <iostream>

Pacman::Pacman() : Movable(1,1,PACMAN,RIGHT) {
	// TODO Auto-generated constructor stub
	this->setLethal(false);
	this->setKillable(true);
	this->TickCount = 0;
	this->setMoving(false);
}

void Pacman::Tick(std::map<std::tuple<int,int>, GameObject*> GameObjects){
	//Check for Collisions
	this->DetectGhostCollision(GameObjects);
	this->DetectWallCollision(GameObjects);
	this->DetectDotCollision(GameObjects);

	//Not Moving
	if(this->getMoving() == false){
		return;
	}

	this->TickCount++;

	if (TickCount > 2){
		switch(this->getDir()){
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

void Pacman::Reset(){
	this->setLocation(1,1);
	this->getPtr()->DecLives(1);
}


void Pacman::DetectWallCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){
	GameObjectStruct Self = this->getStruct();

	std::tuple<int,int> CheckLocation;

	//Check Location relative to Current Direction
	switch(this->getDir()){
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
		//Collision Detected For Wall
		if (ObjectMap[CheckLocation]->getPassable() == false){
			this->setMoving(false);
		}
	}
}

void Pacman::DetectDotCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){

	GameObjectStruct Self = this->getStruct();

	std::tuple<int,int> CheckLocation;


	CheckLocation = std::make_tuple(Self.x, Self.y);


	if(ObjectMap.count(CheckLocation) > 0){
		//Collision Detected

		//Dot
		if (ObjectMap[CheckLocation]->getEdible() == true ){
			std::cout << "Got Dot Collision" << std::endl;
			this->getPtr()->IncScore(ObjectMap[CheckLocation]->getScore());
			this->getPtr()->RemoveObject(ObjectMap[CheckLocation]);
		}

	}
}


void Pacman::DetectGhostCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){


	GameObjectStruct Self = this->getStruct();

	std::tuple<int,int> CheckLocation;


	CheckLocation = std::make_tuple(Self.x, Self.y);


	if(ObjectMap.count(CheckLocation) > 0){
		//Collision Detected
		std::cout << "Got Some Collision" << std::endl;

		//Enemy
		if (ObjectMap[CheckLocation]->getLethal() == true ){
			this->Reset();
		}

	}

}






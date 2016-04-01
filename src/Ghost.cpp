/*
 * Ghost.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: rick
 */

#include "../include/Ghost.h"
#include "../include/Game.h"


Ghost::Ghost(int x, int y, Type type, Direction dir) : Movable(x,y,type,dir) {
	// TODO Auto-generated constructor stub
	this->setPassable(true);
	this->setLethal(true);
	this->setEdible(false);
	this->setScore(1000);
	this->DefaultX = x;
	this->DefaultY = y;
	this->DefaultType = type;
}

void Ghost::Tick(std::map<std::tuple<int,int>, GameObject*> GameObjects){
	this->DetectCollision(GameObjects);


	if(this->getMoving() == true){

		this->TickCount++;

		if(TickCount > 2){
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

	//VERY CRUDE MOVEMENT ALGORITM
	if (this->getMoving() == false){
		this->RandomDirection();
	}else{
		int switchMovementParameter = rand() % 10;
		if (switchMovementParameter == 0){
			this->RandomDirection();
		}

	}
}

void Ghost::RandomDirection(){
	int FourOptions = rand() % 4;
			switch (FourOptions){
			case 0:
				this->GoDown();
				break;
			case 1:
				this->GoLeft();
				break;
			case 2:
				this->GoRight();
				break;
			case 3:
				this->GoUp();
				break;
			}
}

void Ghost::ResolveCollision(GameObject *other){
	//Wall
	if (other->getPassable() == false){
		this->setMoving(false);
	}

}

void Ghost::DetectCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){
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
		//Collision Detected
		this->ResolveCollision(ObjectMap[CheckLocation]);

	}
}


void Ghost::Scare(){
	this->setLethal(false);
	this->setEdible(true);

	GameObjectStruct Str = this->getStruct();
	Str.type = SCARED;
	this->setStruct(Str);
}

void Ghost::deScare(){
	this->setLethal(true);
	this->setEdible(false);

	GameObjectStruct Str = this->getStruct();
	Str.type = this->DefaultType;
	this->setStruct(Str);
}



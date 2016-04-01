/*
 * Pacman.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/Pacman.h"
#include "../include/Game.h"
#include <iostream>

Pacman::Pacman() : Movable(6,5,PACMAN,RIGHT) {
	// TODO Auto-generated constructor stub
	this->setLethal(false);
	this->setKillable(true);
	this->TickCount = 0;
	this->setMoving(false);
}

void Pacman::Tick(std::map<std::tuple<int,int>, GameObject*> GameObjects){
	//Check for Collisions
	this->DetectStaticCollision(GameObjects);
	this->DetectMovingCollision();

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
	this->setLocation(6,5);
	this->getPtr()->DecLives(1);

	for(Ghost* ghost : this->getPtr()->getGhosts()){
		ghost->Reset();
	}
}


void Pacman::DetectStaticCollision(std::map<std::tuple<int,int>, GameObject*> ObjectMap){
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
		GameObject* Obj = ObjectMap[CheckLocation];
		//Collision Detected For Wall
		if (Obj->getPassable() == false){
			this->setMoving(false);
		}
	}

	//Check Current Pacman Location
	CheckLocation = std::make_tuple(Self.x, Self.y);

	if(ObjectMap.count(CheckLocation) > 0){
		GameObject* Obj = ObjectMap[CheckLocation];
		//Collision Detected For Edible
		if (Obj->getEdible()){
			this->getPtr()->IncScore(Obj->getScore());
			this->getPtr()->RemoveObject(Obj);
			//ENERGIZER
			if(Obj->getStruct().type == ENERGIZER){
				this->getPtr()->ScareGhosts();
			}
		}
	}
}

void Pacman::DetectMovingCollision(){
	GameObjectStruct Self = this->getStruct();
	std::vector<Ghost*> Ghosts = this->getPtr()->getGhosts();

	for(Ghost* ghost : Ghosts){
		GameObjectStruct GhostStt = ghost->getStruct();
		if ((GhostStt.x == Self.x) and (GhostStt.y == Self.y)){
			//ENEMY SCARED
			if(ghost->getStruct().type == SCARED){
				this->getPtr()->IncScore(ghost->getScore());
				this->getPtr()->RemoveObject(ghost);
				ghost->Reset();
			}
			//ENEMY LETHAL
			if (ghost->getLethal()){
				this->Reset();
			}
		}
	}
}

void Pacman::ResolveCollision(GameObject *Obj){

	//EDIBLE
	if (Obj->getEdible()){
		this->getPtr()->IncScore(Obj->getScore());
		this->getPtr()->RemoveObject(Obj);
		//ENERGIZER
		if(Obj->getStruct().type == ENERGIZER){
			this->getPtr()->ScareGhosts();
		}

		//ENEMY
		if(Obj->getStruct().type == SCARED){
			Obj->Reset();
		}
	}



	//ENEMY
	if (Obj->getLethal()){
		this->Reset();
	}

}

void Pacman::SDLEventHandler(SDL_Event e, std::map<std::tuple<int,int>, GameObject*> ObjectMap){
	GameObjectStruct Self = this->getStruct();

		std::tuple<int,int> CheckLocation;

		//Check Location relative to Current Direction
		switch(e.key.keysym.sym){
		case SDLK_UP:
			CheckLocation = std::make_tuple(Self.x, Self.y - 1);
			break;
		case SDLK_DOWN:
			CheckLocation = std::make_tuple(Self.x, Self.y + 1);
			break;
		case SDLK_LEFT:
			CheckLocation = std::make_tuple(Self.x - 1, Self.y);
			break;
		case SDLK_RIGHT:
			CheckLocation = std::make_tuple(Self.x + 1, Self.y);
			break;
		default:
			CheckLocation = std::make_tuple(Self.x, Self.y);
			break;
		}

		if(ObjectMap.count(CheckLocation) > 0){
			if (ObjectMap[CheckLocation]->getPassable() == true){
				switch(e.key.keysym.sym){
					case SDLK_UP:
						this->GoUp();
						break;
					case SDLK_DOWN:
						this->GoDown();
						break;
					case SDLK_LEFT:
						this->GoLeft();
						break;
					case SDLK_RIGHT:
						this->GoRight();
						break;
					default:
						break;
					}
			}
		}else{
			switch(e.key.keysym.sym){
			case SDLK_UP:
				this->GoUp();
				break;
			case SDLK_DOWN:
				this->GoDown();
				break;
			case SDLK_LEFT:
				this->GoLeft();
				break;
			case SDLK_RIGHT:
				this->GoRight();
				break;
			default:
				break;
			}

		}
}





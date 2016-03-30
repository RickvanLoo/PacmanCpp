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
	this->DetectCollision(GameObjects);


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




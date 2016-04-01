/*
 * GameObject.cpp

 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/GameObject.h"
#include "../include/Game.h"


GameObject::GameObject(int x, int y, Type type, Direction dir) {
	// TODO Auto-generated constructor stub
	GameObjectStruct structure;
	structure.x = x;
	structure.y = y;
	structure.type = type;
	structure.dir = dir;

	setStruct(structure);
	this->DefaultStruct = structure;

	//Set Flags as if empty space
	setLethal(false);
	setKillable(false);
	setPassable(true);
	setEdible(false);
	setScore(0);

}

void GameObject::setStruct(GameObjectStruct gos){
	this->Info = gos;
}

GameObjectStruct GameObject::getStruct(){
	return this->Info;
}

void GameObject::setLocation(int x,int y){
	this->Info.x = x;
	this->Info.y = y;
}

void GameObject::setLethal(bool input){
	this->Lethal = input;
}

void GameObject::setKillable(bool input){
	this->Killable = input;
}

void GameObject::setPassable(bool input){
	this->Passable = input;
}

void GameObject::setEdible(bool input){
	this->Edible = input;
}

bool GameObject::getLethal(){
	return this->Lethal;
}

bool GameObject::getKillable(){
	return this->Killable;
}

bool GameObject::getPassable(){
	return this->Passable;
}

bool GameObject::getEdible(){
	return this->Edible;
}

void GameObject::setType(Type type){
	this->Info.type = type;
}

void GameObject::setDirection(Direction dir){
	this->Info.dir = dir;
}

void GameObject::setScore(int input){
	this->Score = input;
}

int GameObject::getScore(){
	return this->Score;
}

void GameObject::setPtr(Game *ptr){
	this->GamePtr = ptr;
}

Game* GameObject::getPtr(){
	return this->GamePtr;
}

void GameObject::Reset(){
	this->setStruct(this->DefaultStruct);
}



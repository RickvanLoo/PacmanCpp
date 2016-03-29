/*
 * GameObject.cpp

 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#include "../include/GameObject.h"


GameObject::GameObject(int x, int y, Type type, Direction dir) {
	// TODO Auto-generated constructor stub
	GameObjectStruct structure;
	structure.x = x;
	structure.y = y;
	structure.type = type;
	structure.dir = dir;

	setStruct(structure);
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

bool GameObject::getLethal(){
	return this->Lethal;
}

bool GameObject::getKillable(){
	return this->Killable;
}

bool GameObject::getPassable(){
	return this->Passable;
}

void GameObject::setType(Type type){
	this->Info.type = type;
}

void GameObject::setDirection(Direction dir){
	this->Info.dir = dir;
}


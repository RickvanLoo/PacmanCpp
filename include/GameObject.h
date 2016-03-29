/*
 * GameObject.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef SRC_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_H_

#include "GameObjectStruct.h"

class GameObject {
public:
	GameObject(int, int, Type, Direction);

	/* Get/Set function */
	void setStruct(GameObjectStruct);
	GameObjectStruct getStruct();

	void setLethal(bool);
	bool getLethal();
	void setKillable(bool);
	bool getKillable();

	void setLocation(int, int);

	void setType(Type);
	void setDirection(Direction);

private:
	GameObjectStruct Info;
	bool Lethal;
	bool Killable;
};

#endif /* SRC_GAMEOBJECT_H_ */
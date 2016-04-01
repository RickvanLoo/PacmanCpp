/*
 * Pacman.h
 *
 *  Created on: Mar 29, 2016
 *      Author: rick
 */

#ifndef INCLUDE_PACMAN_H_
#define INCLUDE_PACMAN_H_

#include "Movable.h"
#include <map>
#include <tuple>
#include <SDL2/SDL.h>


class Pacman: public Movable {
public:
	Pacman();
	void Reset();
	void Tick(std::map<std::tuple<int,int>, GameObject*>);
	void SDLEventHandler(SDL_Event, std::map<std::tuple<int,int>, GameObject*>);
private:
	void DetectMovingCollision();
	void DetectStaticCollision(std::map<std::tuple<int,int>, GameObject*>);
	void ResolveCollision(GameObject*);
	int TickCount;

};

#endif /* INCLUDE_PACMAN_H_ */

/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include <SDL2/SDL.h>
#include <vector>
#include "../include/board.h"
#include "../include/main.h"
#include "../include/Game.h"

Game Game(map);

int main(int argc, char* argv[]) {

	// Create a new ui object
	//UI ui(map); // <-- use map from your game objects.



	// Start timer for game update, call this function every 100 ms.
	timer_id = SDL_AddTimer(50, gameUpdate, (void *)nullptr);

	// Example object, this can be removed later


	/* Put game init code here */
	Game.Reset();

	Game.Start();

	SDL_RemoveTimer(timer_id);

    return 0;
}


Uint32 gameUpdate(Uint32 interval, void *param)
{
	Game.Tick();
	/** Do game loop update here **/
	return interval;
}

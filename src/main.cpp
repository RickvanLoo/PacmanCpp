/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "../include/UI.h"
#include "../include/GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>
#include "../include/board.h"
#include "../include/main.h"

int main(int argc, char* argv[]) {

	// Create a new ui object
	UI ui(map); // <-- use map from your game objects.

	// Start timer for game update, call this function every 100 ms.
	timer_id = SDL_AddTimer(100, gameUpdate, (void *)nullptr);

	// Example object, this can be removed later
	GameObjectStruct pacman;
	pacman.x = 1;
	pacman.y = 1;
	pacman.type = PACMAN;
	pacman.dir = UP;

	/* Put game init code here */

	bool quit = false;

	while (!quit){
		// set timeout to limit frame rate
		Uint32 timeout = SDL_GetTicks() + 20;

		// Handle the input
		while (SDL_PollEvent(&e)){
			// Quit button.
			if (e.type == SDL_QUIT){
				quit = true;
			}

			// All keydown events
			if (e.type == SDL_KEYDOWN){
	            switch (e.key.keysym.sym)
	            {
	            case SDLK_LEFT:   /* PUT YOUR CODE HERE */ break;
	            case SDLK_RIGHT:  /* PUT YOUR CODE HERE */ break;
	            case SDLK_UP:     /* PUT YOUR CODE HERE */ break;
	            case SDLK_DOWN:   /* PUT YOUR CODE HERE */; break;
	            case SDLK_ESCAPE: quit= true; break;
	            }
			}
		}

		// Set the score
		ui.setScore(12345); /* <-- Put your code in the setter */

		// Set the amount of lives
		ui.setLives(3); /* <-- Put your code in the setter */

		// Render the scene
		std::vector<GameObjectStruct> objects = {pacman};
		ui.update(objects); /* <-- Put your code in the update function (e.g. game->getStructs()) */

		while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
		    /* ... do work until timeout has elapsed */
		}
	}

	SDL_RemoveTimer(timer_id);

    return 0;
}


Uint32 gameUpdate(Uint32 interval, void *param)
{
	/** Do game loop update here **/
	return interval;
}

/*
 * Game.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: rick
 */

#include "../include/Game.h"

Game::Game(std::vector<std::vector<int>> map) : UI(map) {
	// TODO Auto-generated constructor stub

}

void Game::Reset(){
	std::cout << "Call for Game::Reset()" << std::endl;

	Pacman Pacman;

	this->PlayerObject = Pacman;
	this->CreateWallObjects();

	std::cout << "Counting WALLS: " << this->Walls.size() << std::endl;


	this->setScore(0);

	this->setLives(3);


	// Render the scene
	this->ObjectStructList = {Pacman.getStruct()};
	this->update(this->ObjectStructList);
}

void Game::Start(){
	bool quit = false;

		while (!quit){
			// set timeout to limit frame rate
			Uint32 timeout = SDL_GetTicks() + 20;

			// Handle the input
			while (SDL_PollEvent(&e)){
				// Quit button.
				if (e.type == SDL_QUIT){
					quit = true;
					break;
				}

				// All keydown events
				if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE)){
		            quit= true;
		            break;
				}

				EventHandler(e);
			}

			while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
			    /* ... do work until timeout has elapsed */
			}
		}
}

void Game::UpdateScreen(){
	this->ObjectStructList = {this->PlayerObject.getStruct()};
	this->update(this->ObjectStructList);
}

void Game::EventHandler(SDL_Event e){

	switch(e.key.keysym.sym){
	case SDLK_UP:
		std::cout << "UP!" << std::endl;
		this->PlayerObject.GoUp();
		break;
	case SDLK_DOWN:
		std::cout << "DOWN!" << std::endl;
		this->PlayerObject.GoDown();
		break;
	case SDLK_LEFT:
		std::cout << "LEFT!" << std::endl;
		this->PlayerObject.GoLeft();
		break;
	case SDLK_RIGHT:
		std::cout << "RIGHT!" << std::endl;
		this->PlayerObject.GoRight();
		break;
	}
}

void Game::Tick(){
	this->PlayerObject.Tick();
	this->UpdateScreen();
	CollisionResolver();
}

void Game::CreateWallObjects(){
	this->Walls.clear();

	for(int i=0; i<map.size();i++)
		{
			for(int j=0; j<map[i].size();j++)
			{
				if(map[i][j]==1)
				{
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					GameObject* Object = new GameObject(j,i,WALL,UP);
					Object->setPassable(false);

					this->Walls.insert(std::make_pair(Loc, Object));

				}
			}
		}
}

void Game::CollisionResolver(){
	GameObjectStruct Cur = this->PlayerObject.getStruct();
	std::tuple<int,int> Loc = std::make_tuple(Cur.x, Cur.y);

	if(this->Walls.count(Loc) > 0){
		if(this->PlayerObject.CollideWith(this->Walls[Loc])){

			this->PlayerObject.ResolveCollision(this->Walls[Loc]);

		}
	}
}


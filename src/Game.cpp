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
	Pacman Pacman;

	this->PlayerObject = Pacman;
	this->PlayerObject.setPtr(this);

	this->ObjectStructList = {Pacman.getStruct()};

	this->CreateObjects();

	std::cout << "Counting GameObjects: " << this->GameObjects.size() << std::endl;


	this->setScore(0);

	this->setLives(3);


	// Render the scene
	this->update(this->ObjectStructList);

	std::cout << "Counting StructList: " << this->ObjectStructList.size() << std::endl;
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

				SDLEventHandler(e);
			}

			while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
			    /* ... do work until timeout has elapsed */
			}
		}
}

void Game::UpdateScreen(){
	this->ObjectStructList[0] = this->PlayerObject.getStruct();
	this->update(this->ObjectStructList);
}

void Game::SDLEventHandler(SDL_Event e){

	switch(e.key.keysym.sym){
	case SDLK_UP:
		this->PlayerObject.GoUp();
		break;
	case SDLK_DOWN:
		this->PlayerObject.GoDown();
		break;
	case SDLK_LEFT:
		this->PlayerObject.GoLeft();
		break;
	case SDLK_RIGHT:
		this->PlayerObject.GoRight();
		break;
	}
}

void Game::Tick(){
	this->PlayerObject.Tick(this->GameObjects);
	this->UpdateScreen();
}

void Game::CreateObjects(){
	this->GameObjects.clear();

	for(int i=0; i<map.size();i++)
		{
			for(int j=0; j<map[i].size();j++)
			{
				//WALL
				if(map[i][j]==1)
				{
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					GameObject* Object = new GameObject(j,i,WALL,UP);
					Object->setPassable(false);
					Object->setLethal(false);
					Object->setKillable(false);
					Object->setEdible(false);

					this->GameObjects.insert(std::make_pair(Loc, Object));

				}

				//DOT
				if(map[i][j]==0)
				{
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					GameObject* Object = new GameObject(j,i,DOT,UP);
					Object->setPassable(true);
					Object->setLethal(false);
					Object->setKillable(false);
					Object->setEdible(true);
					Object->setScore(5);

					this->ObjectStructList.push_back(Object->getStruct());

					this->GameObjects.insert(std::make_pair(Loc, Object));

				}
			}
		}
}

void Game::RemoveObject(GameObject *obj){

	GameObjectStruct CurStruct = obj->getStruct();

	for(int i=0; i<this->ObjectStructList.size(); i++){
		GameObjectStruct test = this->ObjectStructList.at(i);
		if ((test.x == CurStruct.x)&&(test.y == CurStruct.y)){


			this->ObjectStructList.erase(this->ObjectStructList.begin()+i);

			std::tuple<int,int> Loc = std::make_tuple(test.x,test.y);
			this->GameObjects.erase(Loc);




		}

	}

}

void Game::IncScore(int input){
	this->setScore(this->getScore()+input);
}




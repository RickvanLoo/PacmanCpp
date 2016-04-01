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

	this->CreateObjects();

	std::cout << "Counting GameObjects: " << this->GameObjects.size() << std::endl;



	this->setScore(0);

	this->setLives(3);


	// Render the scene
	this->ObjectStructList.clear();

	for(auto ent1 : this->GameObjects) {
		this->ObjectStructList.push_back(ent1.second->getStruct());
	}

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


				//SDLEventHandler(e);
				this->PlayerObject.SDLEventHandler(e,this->GameObjects);
			}

			while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
			    /* ... do work until timeout has elapsed */
			}
		}
}

void Game::UpdateScreen(){
	this->ObjectStructList.clear();

	// Favor Ghosts for rendering.
	for(auto const ent1 : this->GameObjects) {
		if((ent1.second->getLethal()) or ent1.second->getStruct().type == SCARED){
			this->ObjectStructList.push_back(ent1.second->getStruct());

		}else{
			this->ObjectStructList.insert(this->ObjectStructList.begin(), ent1.second->getStruct());

		}

	}

	this->ObjectStructList.push_back(this->PlayerObject.getStruct());

	this->update(this->ObjectStructList);
}


void Game::Tick(){
	//Check For GameOver
	if(this->getLives() == 0){
		this->Reset();
	}

	this->CallTimer();

	this->PlayerObject.Tick(this->GameObjects);
	for (Ghost* Ghost : this->Ghosts){
		Ghost->Tick(this->GameObjects);
	}
	this->UpdateScreen();
}

void Game::CreateObjects(){
	this->GameObjects.clear();

	for(int i=0; i<map.size();i++)
		{
			for(int j=0; j<map[i].size();j++)
			{
				//BLINKY
				if(map[i][j]==2){
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					Ghost* Object = new Ghost(j,i,BLINKY,RIGHT);

					this->Ghosts.push_back(Object);
					this->GameObjects.insert(std::make_pair(Loc, Object));
				}
				//PINKY
				if(map[i][j]==3){
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					Ghost* Object = new Ghost(j,i,PINKY,UP);


					this->Ghosts.push_back(Object);
					this->GameObjects.insert(std::make_pair(Loc, Object));
				}
				//INKY
				if(map[i][j]==4){
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					Ghost* Object = new Ghost(j,i,INKY,UP);


					this->Ghosts.push_back(Object);
					this->GameObjects.insert(std::make_pair(Loc, Object));
				}
				//CLYDE
				if(map[i][j]==5){
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					Ghost* Object = new Ghost(j,i,CLYDE,LEFT);


					this->Ghosts.push_back(Object);
					this->GameObjects.insert(std::make_pair(Loc, Object));
				}

				//WALL
				if(map[i][j]==1)
				{
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					GameObject* Object = new GameObject(j,i,WALL,UP);
					Object->setPassable(false);
					Object->setLethal(false);
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
					Object->setEdible(true);
					Object->setScore(5);

					this->GameObjects.insert(std::make_pair(Loc, Object));

				}

				//ENERGIZERS
				if(map[i][j]==8){
					std::tuple<int,int> Loc = std::make_tuple(j,i);
					GameObject* Object = new GameObject(j,i,ENERGIZER,UP);
					Object->setPassable(true);
					Object->setLethal(false);
					Object->setEdible(true);
					Object->setScore(0);

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

void Game::DecLives(int input){
	this->setLives(this->getLives()-input);
}

std::vector<Ghost*> Game::getGhosts(){
	return this->Ghosts;
}

void Game::CallTimer(){
	if(this->EnableTimer){
		if(this->TimerCount > 140){
			//Descare Ghosts
			for(Ghost* ghost: this->Ghosts){
				ghost->deScare();
			}


		}
		this->TimerCount++;
	}
}

void Game::ScareGhosts(){
	this->EnableTimer = true;
	this->TimerCount = 0;
	//ScareAllGhosts
	for(Ghost* ghost: this->Ghosts){
		ghost->Scare();
	}

}




#pragma once
#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "BackgroundObject.h"
#include "SpriteUser.h"

//To Do:
//Print a sprite
// Print a sprite that responds to keyboard inputs


//Start - For setting up resources and containing the game
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	
	//Set up game resources
		//Main window
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 4), "Magician Guy");
		//Origin set to centre of screen
	origin_x = 320;
	origin_y = 240;


		//Set up objects
	test1.SetPosition(0, 0, origin_x, origin_y);


	test2.SetPosition(120, 50, origin_x, origin_y);



	_gameState = Playing;

	//Game Loop
	while (!IsExiting()) 
	{
		Game::GameLoop();
	}


	//Clean resources and terminate
	_mainWindow.close();

}


//GameLoop - For regularly updating the game.
void Game::GameLoop(void)
{
	sf::Time t1 = Game::clock.getElapsedTime();
	float timeDelta;

	switch (_gameState)
	{
	case Playing:
		_mainWindow.clear(sf::Color(0, 0, 0));
		t1 = t1 - t2; //Get the time since that last update
		timeDelta = t1.asSeconds();

		test1.Draw(_mainWindow);
		test2.Update(timeDelta, origin_x, origin_y);
		test2.Draw(_mainWindow);
		_mainWindow.display();
		
		t2 = t2 + t1;
		break;
	default:
		break;
	}



	return;
}


//IsExiting - Check game request for exit
bool Game::IsExiting(void)
{
	if (_gameState == Exiting) {
		return true;
	}
	return false;
}


//Static class variables need to be initialised (standard practice)
sf::RenderWindow Game::_mainWindow;
Game::GameState Game::_gameState;
BackgroundObject Game::test1;
SpriteUser Game::test2;
float Game::origin_x;
float Game::origin_y;
sf::Time Game::t2;
sf::Clock Game::clock;
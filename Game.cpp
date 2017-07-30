#pragma once
#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "BackgroundObject.h"
#include "SpriteUser.h"

//To Do:


//On Hold:
//SpriteUser
	//To implement image cache and changing image (animation)
// Implement gameobjectmanager
	//Also implement separation between background and objects that need updating
//


//Start - For setting up resources and containing the game
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	
	//Set up game resources
		//Main window
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 4), "Magician Guy");
		//Origin 
	fOrigin_x = 320;
	fOrigin_y = 240;


		//Objects
	InitialiseObjects();

		//Control flow
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

	switch (_gameState)
	{
	case Playing:
		_mainWindow.clear(sf::Color(0, 0, 0));


		_gameObjectManager.UpdateAll();
		_gameObjectManager.DrawAll(_mainWindow);

		_mainWindow.display();
		
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

void Game::InitialiseObjects()
{
	BackgroundObject* test3 = new BackgroundObject();
	test3->SetPosition(90, 30, fOrigin_x, fOrigin_y);
	_gameObjectManager.Add("testing", test3);

	BackgroundObject* test2 = new BackgroundObject();
	test2->SetPosition(90, 0, fOrigin_x, fOrigin_y);
	_gameObjectManager.Add("testing1", test2);

	SpriteUser* test1 = new SpriteUser();
	test1->SetPosition(0, 0, fOrigin_x, fOrigin_y);
	_gameObjectManager.Add("testing2", test1);



}



//GetWindow - Retrieve mainWindow
sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

//GetGameObjectManger - Retrieve object manager
GameObjectManager& Game::GetGameObjectManager()
{
	return _gameObjectManager;
}

//GetOriginX - Retrieve origin x coordinate
float& Game::GetOriginX()
{
	return fOrigin_x;
}

//GetOriginY - Retrieve origin y coodinate
float& Game::GetOriginY()
{
	return fOrigin_y;
}



//Static class variables need to be initialised (standard practice)
sf::RenderWindow Game::_mainWindow;
Game::GameState Game::_gameState;
float Game::fOrigin_x;
float Game::fOrigin_y;
sf::Clock Game::clock;
GameObjectManager Game::_gameObjectManager;
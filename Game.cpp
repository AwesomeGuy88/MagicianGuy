#pragma once
#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "SpriteBackground.h"
#include "SpriteUser.h"

//To Do:
//Object Collisions

//On Hold:
//SpriteUser
	//To implement origin manipulation
	//To implement image cache and changing image (animation)
// Implement gameobjectmanager
	//Also implement separation between background and objects that need updating
// DataHandler
	//Convert to vector, to reduce wastage of space
	//Can break code if going beyond the limit of number of elements



//Start - For setting up resources and containing the game
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	
	//Set up game resources
		//Main window
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 4), "Magician Guy");
		//Origin (Camera Location)
	fOrigin_x = 320;
	fOrigin_y = 240;
		//Objects
	InitialiseObjects();
	GameObjectManager* pGM0 = &_gameObjectManager0;
	GameObjectManager* pGM1 = &_gameObjectManager1;
	GameObjectManager* pGM2 = &_gameObjectManager2;
	_dataHandler.ExtractDataAndCreate(pGM0, pGM1, pGM2, fOrigin_x, fOrigin_y);

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

		//Background Layer
		_gameObjectManager0.UpdateAll();
		_gameObjectManager0.DrawAll(_mainWindow);
		//Layer 1
		_gameObjectManager1.UpdateAll();
		_gameObjectManager1.DrawAll(_mainWindow);
		//Layer 2
		_gameObjectManager2.UpdateAll();
		_gameObjectManager2.DrawAll(_mainWindow);

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
	
	SpriteBackground* test3 = new SpriteBackground();
	test3->SetPosition(90, 30, fOrigin_x, fOrigin_y);
	_gameObjectManager0.Add("testing", test3);

	SpriteBackground* test2 = new SpriteBackground();
	test2->SetPosition(90, -90, fOrigin_x, fOrigin_y);
	_gameObjectManager1.Add("testing1", test2);

	SpriteUser* test1 = new SpriteUser();
	test1->SetPosition(0, 0, fOrigin_x, fOrigin_y);
	_gameObjectManager1.Add("testing2", test1);

	SpriteBackground* test4 = new SpriteBackground();
	test4->SetPosition(90, 60, fOrigin_x, fOrigin_y);
	_gameObjectManager2.Add("testing4", test4);

}



//GetWindow - Retrieve mainWindow
sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

//GetGameObjectManger - Retrieve object manager
GameObjectManager& Game::GetGameObjectManager0()
{
	return _gameObjectManager0;
}

//GetGameObjectManger - Retrieve object manager
GameObjectManager& Game::GetGameObjectManager1()
{
	return _gameObjectManager1;
}
//GetGameObjectManger - Retrieve object manager
GameObjectManager& Game::GetGameObjectManager2()
{
	return _gameObjectManager2;
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
std::map<std::pair<int, int>, std::string> Game::_occupancyGrid;
sf::Clock Game::clock;
GameObjectManager Game::_gameObjectManager0;
GameObjectManager Game::_gameObjectManager1;
GameObjectManager Game::_gameObjectManager2;
DataHandler Game::_dataHandler;
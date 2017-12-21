#pragma once
#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "SpriteBackground.h"
#include "SpriteUser.h"

//To Do



//Restrictions
// Obstacle Grid is currently limited in size
// Number of obstacles that can be generated through GOM is limited

//Improvements for later
// - Explore scalability for map.cpp (Templates? data structures?)


//Start - For setting up resources and containing the game
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	
	//Set up game resources
		//Main window
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 4), "Magician Guy");
		//Map
	

	_map.InitialiseMap();
		//Origin (Camera Location)
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

	GameObjectManager* pGM0 = &_gameObjectManager0;
	GameObjectManager* pGM1 = &_gameObjectManager1;
	GameObjectManager* pGM2 = &_gameObjectManager2;
	_map.CreateGrass(pGM0, fOrigin_x, fOrigin_y, 20);

	SpriteUser* test1 = new SpriteUser();
	test1->SetPosition(0, 0, fOrigin_x, fOrigin_y);
	test1->SetObjectID("User");
	_gameObjectManager1.Add("testing2", test1);


	SpriteObstacle* test5 = new SpriteObstacle();
	test5->Load("ArtAssets/Mage/MageLeft.fw.png");
	test5->SetPosition(45, 60, fOrigin_x, fOrigin_y);
	test5->SetObjectID("ob02");
	_gameObjectManager2.Add("testing5", test5);
	_map.PlaceIntoGrid(test5, test5->GetPosition());

	_dataHandler.ExtractDataAndCreate(pGM0, pGM1, pGM2, fOrigin_x, fOrigin_y);
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

//GetGameObjectManger - Retrieve object manager
Map* Game::GetMap()
{
	return &_map;
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
Map Game::_map;


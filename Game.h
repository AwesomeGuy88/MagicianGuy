
//Game - The game class divides runtime into different states that give us a
//		better understanding of the code and the ability to departmentalise it.

#pragma once
#include "stdafx.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
#include "SpriteBackground.h"
#include "SpriteUser.h"
#include "DataHandler.h"
#include "Map.h"


class Game
{
public:
	static void Start(void);

	static GameObjectManager& GetGameObjectManager0();
	static GameObjectManager& GetGameObjectManager1();
	static GameObjectManager& GetGameObjectManager2();
	static Map* GetMap();

	static sf::RenderWindow& GetWindow();
	static float& GetOriginX();
	static float& GetOriginY();

	static sf::Clock clock;

	const static int SCREEN_WIDTH = 640;
	const static int SCREEN_HEIGHT = 480;

private:
	static void GameLoop(void);
	static bool IsExiting(void);

	static void InitialiseObjects();
	static void UpdateObjects();


	enum GameState {
		Uninitialized, Paused, ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static float fOrigin_x, fOrigin_y;
	static GameObjectManager _gameObjectManager0; //Background Layer
	static GameObjectManager _gameObjectManager1; //Layer 1
	static GameObjectManager _gameObjectManager2; //Layer 2
	static DataHandler _dataHandler;
	static Map _map;
};



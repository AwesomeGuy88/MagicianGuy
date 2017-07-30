
//Game - The game class divides runtime into different states that give us a
//		better understanding of the code and the ability to departmentalise it.

#pragma once
#include "stdafx.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "BackgroundObject.h"
#include "SpriteUser.h"


class Game
{
public:
	static void Start(void);

	static sf::Clock clock;

	const static int SCREEN_WIDTH = 640;
	const static int SCREEN_HEIGHT = 480;

private:
	static void GameLoop(void);
	static bool IsExiting(void);


	enum GameState {
		Uninitialized, Paused, ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static BackgroundObject test1;
	static SpriteUser Game::test2;
	static float origin_x, origin_y;

	static sf::Time t2;
};



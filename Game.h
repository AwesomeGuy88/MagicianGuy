
//Game - The game class divides runtime into different states that give us a
//		better understanding of the code and the ability to departmentalise it.

#pragma once
#include <SFML/Window.hpp>
#include "BackgroundObject.h"


class Game
{
public:
	static void Start(void);


	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static void GameLoop(void);
	static bool IsExiting(void);


	enum GameState {
		Uninitialized, Paused, ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static BackgroundObject test1;

};



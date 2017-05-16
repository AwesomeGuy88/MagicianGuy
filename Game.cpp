#pragma once
#include "stdafx.h"
#include "Game.h"



//Start - For setting up resources and containing the game
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	
	//Set up game resources
	_mainWindow.create(sf::VideoMode(640, 480, 4), "Magician Guy");			//Main Window



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
	_gameState = Playing;
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
#pragma once
#include "VisibleGameObject.h"
#include "SpriteObstacle.h"
#include "GameObjectManager.h"
#include <memory>

//To Do
//Function that places image to occupancy grid
//FUnction that prints out all map information
//functions to manage origin

class Map {
public:
	Map();
	virtual ~Map();

	void InitialiseMap();
	void CreateGrass(GameObjectManager* _gameObjectManager, float fOrigin_x, float fOrigin_y, int n_size);

	bool PlaceIntoGrid(SpriteObstacle* Obj, sf::Vector2f position);
	void RemoveFromGrid(SpriteObstacle* Obj, sf::Vector2f position);
	bool IsOccupied(SpriteObstacle* Obj, sf::Vector2f position);


private:
	std::unique_ptr<std::string[]> _occupancy_grid;
	int _occupancy_grid_length;
	bool _is_initialised;
};
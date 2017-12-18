#pragma once
#include "VisibleGameObject.h"
#include "SpriteObstacle.h"
#include <memory>

//To Do
//Function that places image to occupancy grid
//FUnction that prints out all map information
//functions to manage origin

class Map {
public:
	Map();
	~Map();

	void InitialiseMap();
	bool PlaceIntoGrid(SpriteObstacle* Obj, sf::Vector2f position);
	void RemoveFromGrid(SpriteObstacle* Obj, sf::Vector2f position);


	bool IsOccupied(SpriteObstacle* Obj, sf::Vector2f position);

private:
	//std::map<std::pair<int, int>, std::string> _occupancy_grid;
	std::unique_ptr<std::string> _occupancy_grid;
	int _occupancy_grid_length;
	bool _is_initialised;
};
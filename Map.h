#pragma once
#include "VisibleGameObject.h"
#include "SpriteObstacle.h"

//To Do
//Function that places image to occupancy grid
//FUnction that prints out all map information
//functions to manage origin

class Map {
public:
	Map();
	~Map();

	void PlaceIntoGrid(SpriteObstacle* Obj, sf::Vector2f position);


	bool IsOccupied(std::string pixel_occupancy[16][16], sf::Vector2f position);

private:
	//std::map<std::pair<int, int>, std::string> _occupancy_grid;
	std::string *_occupancy_grid;
	int _occupancy_grid_length = 1000;
};
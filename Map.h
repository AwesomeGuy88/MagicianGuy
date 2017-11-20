#pragma once
#include "VisibleGameObject.h"

//To Do
//Function that places image to occupancy grid
//FUnction that prints out all map information
//functions to manage origin

class Map {
public:
	Map(int x, int y);
	~Map();

	void ToOccupancyGrid(VisibleGameObject* Obj);

private:
	std::map<std::pair<int, int>, std::string> occupancyGrid;
};
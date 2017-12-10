#include "stdafx.h"
#include "Map.h"


//Constructor - Initialises the size of the occupancy grid
Map::Map() 
{
	_occupancy_grid = new std::string[_occupancy_grid_length * _occupancy_grid_length];
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			_occupancy_grid[i*_occupancy_grid_length + j] = "NULL";
		}
	}
}


//Destructor
Map::~Map() 
{
	delete [] _occupancy_grid;
}


//PlaceIntoGrid - Safely adds the object to the grid at the specified position.
//					Position is interpretted as the top right position of the object
//	1) Determines whether grid positions are already occupied
//  2) If unoccupied, places specified object onto grid
//  3) Returns true/false depending on operation success
void Map::PlaceIntoGrid(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;
	std::string ObjectID;

	//Check occupancy
	std::string pixel_occupancy[16][16];
	Obj->GetPixelOccupancy(pixel_occupancy);
	if (IsOccupied(pixel_occupancy, position)) {}
	else { //If unoccupied then place object
		ObjectID = Obj->GetObjectID();
		for (int i = 0; i < 16; i++) { //Loop from top right corner
			for (int j = 0; j > -16; j--) {
				if (pixel_occupancy[i][j] != "NULL") {

					x = position.x; +j + _occupancy_grid_length / 2;
					y = position.y; +i + _occupancy_grid_length / 2;
					_occupancy_grid[y*_occupancy_grid_length + x] = ObjectID;
				}
			}
		}
	}
}


//RemoveFromGrid - Reverts all occupancy cells to null at specified location
void Map::RemoveFromGrid(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;

	//Get object occupancy data
	std::string pixel_occupancy[16][16];
	Obj->GetPixelOccupancy(pixel_occupancy);

	for (int i = 0; i < 16; i++) { //Loop from top right corner
		for (int j = 0; j > -16; j--) {
			if (pixel_occupancy[i][j] != "NULL") {

				//Set desired cell to null
				x = position.x; +j + _occupancy_grid_length / 2;
				y = position.y; +i + _occupancy_grid_length / 2;
				_occupancy_grid[y*_occupancy_grid_length + x] = "NULL";
			}
		}
	}
}


//IsOccupied - Checks whether the specified position of an object is occupied or not
// 1) Loops through pixel occupancy of image and compares to grid
// 2) Returns true/false based on the result
bool Map::IsOccupied(std::string pixel_occupancy[16][16], sf::Vector2f position)
{
	int x, y;
	
	//Loop through all occupancy pixels starting from the top right corner
	for (int i = 0; i < 16; i++) { //Rows
		for (int j = 0; j > -16; j--) { //Columns

			//If desired occupancy conflicts with occupied space then return
			if (pixel_occupancy[i][j] != "NULL") {
				
				x = position.x; + j + _occupancy_grid_length/2;
				y = position.y; + i + _occupancy_grid_length/2;
				if (_occupancy_grid[y*_occupancy_grid_length + x] != "NULL") { //Desired position is occupied
					return true;
				}
			}
		}
	}

	return false;
}
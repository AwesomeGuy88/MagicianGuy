#include "stdafx.h"
#include "Map.h"


//Constructor - Initialises the size of the occupancy grid
Map::Map() :
	_is_initialised(false),
	_occupancy_grid(new std::string[400 * 400])
{
	/*_occupancy_grid = new std::string[_occupancy_grid_length * _occupancy_grid_length];
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			_occupancy_grid[i*_occupancy_grid_length + j] = "NULL";
		}
	}*/
}


//Destructor
Map::~Map()
{
	//delete[] _occupancy_grid;
}


//InitialiseMap - Memory for the occupancy grid is allocated by game.cpp to reduce
//				the risk of memory leaks.
void Map::InitialiseMap() {
	//_occupancy_grid(new std::string[200 * 200]);
	_occupancy_grid_length = 400;

	for (int i = 0; i < _occupancy_grid_length; i++) {
		for (int j = 0; j < _occupancy_grid_length; j++) {
			_occupancy_grid.get()[i*_occupancy_grid_length + j] = "NULL";
		}
	}

	_is_initialised = true;
}


//PlaceIntoGrid - Safely adds the object to the grid at the specified position.
//					Position is interpretted as the top right position of the object
//	1) Determines whether grid positions are already occupied
//  2) If unoccupied, places specified object onto grid
//  3) Returns true/false depending on operation success
bool Map::PlaceIntoGrid(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;
	std::string ObjectID;
	std::string pixel_occupancy[16][16];

	//Set Boundaries
	if ((position.x > (_occupancy_grid_length / 2)) || position.x < (-_occupancy_grid_length / 2)) {
		return false;
	} else if ((position.y > (_occupancy_grid_length / 2)) || position.y < (-_occupancy_grid_length / 2)) {
		return false;
	}

	//Check occupancy
	ObjectID = Obj->GetObjectID();
	Obj->GetPixelOccupancy(pixel_occupancy);
	/*if (IsOccupied(pixel_occupancy, position, ObjectID)) { 
		std::cout << "Occupied" << std::endl;
		return false;
	}
	else {*/
	//If unoccupied then place object
		for (int i = 0; i < 16; i++) { //Loop from top right corner
			for (int j = 0; j < 16; j++) {
				if (pixel_occupancy[i][j] != "NULL") {

					x = (int)position.x + j + (_occupancy_grid_length / 2);
					y = (int)position.y - i + (_occupancy_grid_length / 2);
					_occupancy_grid.get()[y*_occupancy_grid_length + x] = ObjectID;
					//std::cout << " grid value assigned: " << _occupancy_grid.get()[y*_occupancy_grid_length + x];
				}
			}
		}
	//}
	return true;
}


//RemoveFromGrid - Reverts all occupancy cells to null at specified location
void Map::RemoveFromGrid(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;

	//Set Boundaries
	if ((position.x > (_occupancy_grid_length / 2)) || position.x < (-_occupancy_grid_length / 2)) {
		return;
	}
	else if ((position.y >(_occupancy_grid_length / 2)) || position.y < (-_occupancy_grid_length / 2)) {
		return;
	}

	//Get object occupancy data
	std::string pixel_occupancy[16][16];
	Obj->GetPixelOccupancy(pixel_occupancy);

	for (int i = 0; i < 16; i++) { //Loop from top right corner
		for (int j = 0; j < 16; j++) {
			if (pixel_occupancy[i][j] != "NULL") {

				//Set desired cell to null
				x = (int)position.x + j + (_occupancy_grid_length / 2);
				y = (int)position.y - i + (_occupancy_grid_length / 2);
				_occupancy_grid.get()[y*_occupancy_grid_length + x] = "NULL";
			}
		}
	}
}


//IsOccupied - Checks whether the specified position of an object is occupied or not
// 1) Loops through pixel occupancy of image and compares to grid
// 2) Returns true if occupied, false if unoccupied
bool Map::IsOccupied(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;
	std::string ObjectID = Obj->GetObjectID();
	std::string pixel_occupancy[16][16];
	Obj->GetPixelOccupancy(pixel_occupancy);
	//Loop through all occupancy pixels starting from the top right corner
	for (int i = 0; i < 16; i++) { //Rows
		for (int j = 0; j < 16; j++) {

			//If desired occupancy conflicts with occupied space then return
			if (pixel_occupancy[i][j] != "NULL") {
				
				x = (int)position.x + j + (_occupancy_grid_length / 2);
				y = (int)position.y - i + (_occupancy_grid_length / 2);
				//std::cout << "NOTNULL?: " << (_occupancy_grid.get()[y*_occupancy_grid_length + x] != "NULL")
				//	<< "  NOTOBJID?: " << (_occupancy_grid.get()[y*_occupancy_grid_length + x] != ObjectID) << std::endl
					//<< "  ObjID: " << _occupancy_grid.get()[y*_occupancy_grid_length + x] << std::endl;
				
				if ((_occupancy_grid.get()[y*_occupancy_grid_length + x] != "NULL") && 
					(_occupancy_grid.get()[y*_occupancy_grid_length + x] != ObjectID) &&  //Desired position is occupied
					(_occupancy_grid.get()[y*_occupancy_grid_length + x] != "")) {
					return true;
				}
			}
		}
	}

	return false;
}
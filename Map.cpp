#include "stdafx.h"
#include "Map.h"
#include "SpriteBackground.h"


//Constructor - Initialises the size of the occupancy grid
Map::Map() :
	_is_initialised(false),
	_occupancy_grid_length(-1)
{
	_occupancy_grid = std::make_unique<std::string[]>(160000);
}


//Destructor
Map::~Map()
{

}


//InitialiseMap - Members of the grid set to NULL
//	Size of occupancy grid is currently modifiable
void Map::InitialiseMap() 
{
	_occupancy_grid_length = 400; //Size of occupancy grid

	for (int i = 0; i < _occupancy_grid_length; i++) {
		for (int j = 0; j < _occupancy_grid_length; j++) {
			_occupancy_grid.get()[i*_occupancy_grid_length + j] = "NULL"; //Inidividual cells set to null
		}
	}

	_is_initialised = true;
}


//CreateGrass - Creates an area of grass according to specified inputs
//	1) Loops through desired size
//	2) Creates grass sprites and assigns to map
void Map::CreateGrass(GameObjectManager* _gameObjectManager, float fOrigin_x, float fOrigin_y, int n_size)
{
	std::string sz_name;
	int x, y = 0;
	
	for (int i = 0; i < n_size; i++) {
		for (int j = 0; j < n_size; j++) {
			SpriteBackground* temp = new SpriteBackground();

			sz_name = "Grass" + std::to_string(i*n_size + j); // Set Name

			temp->Load("ArtAssets/Environment/GrassTile.fw.png"); //Load Tile

			x = i * 16 - (n_size * 16 / 2);
			y = j * 16 - (n_size * 16 / 2);
			temp->SetPosition(x, y, fOrigin_x, fOrigin_y); // Set Position


			_gameObjectManager->Add(sz_name, temp); //Managed by GOM

		}
	}
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

	//Set Boundaries (Temporary protection)
	if ((position.x > (_occupancy_grid_length / 2)) || position.x < (-_occupancy_grid_length / 2)) {
		return false;
	} else if ((position.y > (_occupancy_grid_length / 2)) || position.y < (-_occupancy_grid_length / 2)) {
		return false;
	}

	//Get object data
	ObjectID = Obj->GetObjectID();
	Obj->GetPixelOccupancy(pixel_occupancy);

	//Assign image data to grid
	for (int i = 0; i < 16; i++) { 
		for (int j = 0; j < 16; j++) {
			if (pixel_occupancy[i][j] != "NULL") {
				x = (int)position.x + j + (_occupancy_grid_length / 2);
				y = (int)position.y - i + (_occupancy_grid_length / 2);
				_occupancy_grid.get()[y*_occupancy_grid_length + x] = ObjectID;
			}
		}
	}

	return true;
}


//RemoveFromGrid - Reverts all occupancy cells to null at specified location
void Map::RemoveFromGrid(SpriteObstacle* Obj, sf::Vector2f position)
{
	int x, y;
	std::string pixel_occupancy[16][16];

	//Set Boundaries
	if ((position.x > (_occupancy_grid_length / 2)) || position.x < (-_occupancy_grid_length / 2)) {
		return;
	}
	else if ((position.y >(_occupancy_grid_length / 2)) || position.y < (-_occupancy_grid_length / 2)) {
		return;
	}

	//Get object data
	Obj->GetPixelOccupancy(pixel_occupancy);

	//Nullify image data from grid
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (pixel_occupancy[i][j] != "NULL") {
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

	//Get object data
	Obj->GetPixelOccupancy(pixel_occupancy);

	//Check if desired cells are occupied
	for (int i = 0; i < 16; i++) { //Rows
		for (int j = 0; j < 16; j++) {
			if (pixel_occupancy[i][j] != "NULL") {
				x = (int)position.x + j + (_occupancy_grid_length / 2);
				y = (int)position.y - i + (_occupancy_grid_length / 2);
				
				if ((_occupancy_grid.get()[y*_occupancy_grid_length + x] != "NULL") && 
					(_occupancy_grid.get()[y*_occupancy_grid_length + x] != ObjectID) && 
					(_occupancy_grid.get()[y*_occupancy_grid_length + x] != "")) {
					return true;  //Desired position is occupied
				}
			}
		}
	}

	return false;
}
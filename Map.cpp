#include "stdafx.h"
#include "Map.h"


//Constructor - Initialises the occupancy grid
Map::Map(int x, int y) 
{
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			occupancyGrid[std::make_pair(i, j)] = "NULL";
		}
	}
}


//Destructor
Map::~Map() 
{

}


//ToOccupancyGrid
void Map::ToOccupancyGrid(VisibleGameObject* Obj)
{
	int x, y;
	sf::Image tempImage = Obj->GetTexture().copyToImage();

	//Loop through pixels in texture
	for (int j = 0; j < tempImage.sf::Image::getSize().y; j++) {
		for (int i = 0; i < tempImage.sf::Image::getSize().x; i++) {

			if (tempImage.getPixel(i, j).a != 0) { //Assign to occupancy grid if non alpha values
				x = Obj->GetPosition().x; -tempImage.sf::Image::getSize().x + i;
				y = Obj->GetPosition().y; -tempImage.sf::Image::getSize().y + j;
				occupancyGrid[std::make_pair(x, y)] = Obj->GetObjectID();
			}
		}
	}
}
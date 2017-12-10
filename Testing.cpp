#include "stdafx.h"
#include "Testing.h"
#include "SpriteBackground.h"
#include "GameObjectManager.h"
#include "SpriteObstacle.h"
#include "Map.h"


//Convert image and fill occupancy grid
void Testing::Start(void)
{
	//Initialisation
	std::map<std::pair<int, int>, std::string> occupancyGrid;
	Map _testMap;
	GameObjectManager _gameObjectManager1; //GameObject manager required to prevent memory leaks

	//Creating Sprite for testing
	SpriteObstacle* temp = new SpriteObstacle();
	temp->SetPosition(0, 0, 320, 240);
	temp->Load("ArtAssets/Environment/Wall7.fw.png");
	temp->SetObjectID("ID12");
	_gameObjectManager1.Add("testing", temp);


	//TESTING//
	
	//Map Testing
	
	sf::Vector2f position;
	std::string pixel_occupancy[16][16];
	bool output;
	output = _testMap.IsOccupied(pixel_occupancy, position);
	std::cout << output << std::endl;
	_testMap.PlaceIntoGrid(temp, position);
	output = _testMap.IsOccupied(pixel_occupancy, position);
	std::cout << output << std::endl;
	_testMap.RemoveFromGrid(temp, position);
	output = _testMap.IsOccupied(pixel_occupancy, position);
	std::cout << output << std::endl;


	/* PIXEL OCCUPANCY
	std::string pixel_array[16][16];
	temp->GetPixelOccupancy(pixel_array);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << pixel_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	return;
}
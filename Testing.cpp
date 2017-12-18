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
	GameObjectManager _gameObjectManager1; //GameObject manager required to prevent memory leaks

	//Creating Sprites for testing
	SpriteObstacle* temp = new SpriteObstacle();
	temp->SetPosition(0, 0, 320, 240);
	temp->Load("ArtAssets/Environment/Wall7.fw.png");
	temp->SetObjectID("ID12");
	_gameObjectManager1.Add("testing", temp);

	SpriteObstacle* temp2 = new SpriteObstacle();
	temp2->SetPosition(0, 0, 320, 240);
	temp2->Load("ArtAssets/Mage/MageFront.png");
	temp2->SetObjectID("ID12");
	_gameObjectManager1.Add("testing2", temp2);

	SpriteObstacle* temp1 = new SpriteObstacle();
	temp1->SetPosition(0, 0, 320, 240);
	temp1->Load("ArtAssets/Environment/Wall7.fw.png");
	temp1->SetObjectID("ID13");
	_gameObjectManager1.Add("testing1", temp1);


	//TESTING//
	
	/*
	//Map Testing
	//Init
	bool output;
	sf::Vector2f position;
	std::string pixel_occupancy[16][16];

	//Create map
	Map _testMap;
	_testMap.InitialiseMap();

	//Place obj 1 into grid
	output = _testMap.PlaceIntoGrid(temp1, temp1->GetPosition());
	std::cout << "Placement of 1: " << output << std::endl;

	//Check if grid is occupied for obj 0
	std::string objid = temp->GetObjectID();
	temp->GetPixelOccupancy(pixel_occupancy);
	position = temp->GetPosition();
	output = _testMap.IsOccupied(temp, position);
	std::cout << "Checking from 0: " << output << std::endl;

	//Attempt to place obj 0
	output = _testMap.PlaceIntoGrid(temp, position);
	std::cout << "Attempt to place 0: " <<  output << std::endl;
	/*
	 = _testMap.IsOccupied(pixel_occupancy, position, objid);
	std::cout << output << std::endl;
	_testMap.RemoveFromGrid(temp, position);
	output = _testMap.IsOccupied(pixel_occupancy, position, objid);
	std::cout << output << std::endl;
	*/

	// PIXEL OCCUPANCY
	std::string pixel_array[16][16];
	temp2->GetPixelOccupancy(pixel_array);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << pixel_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	

	return;
}
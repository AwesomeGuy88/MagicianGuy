#include "stdafx.h"
#include "Testing.h"
#include "SpriteBackground.h"
#include "GameObjectManager.h"
#include "SpriteObstacle.h"



//Convert image and fill occupancy grid
void Testing::Start(void)
{
	//Initialisation
	std::map<std::pair<int, int>, std::string> occupancyGrid;
	GameObjectManager _gameObjectManager1; //GameObject manager required to prevent memory leaks

	//Creating Sprite for testing
	SpriteObstacle* temp = new SpriteObstacle();
	temp->SetPosition(0, 0, 320, 240);
	temp->Load("ArtAssets/Environment/Wall7.fw.png");
	temp->SetObjectID("ID12");
	_gameObjectManager1.Add("testing", temp);


	//TESTING//
	std::string pixel_array[16][16];
	temp->GetPixelOccupancy(pixel_array);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << pixel_array[i][j] << " ";
		}
		std::cout << std::endl;
	}


	return;
}
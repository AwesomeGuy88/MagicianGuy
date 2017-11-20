#include "stdafx.h"
#include "Testing.h"
#include "SpriteBackground.h"
#include "GameObjectManager.h"



//Convert image and fill occupancy grid
void Testing::Start(void)
{
	//Initialisation
	std::map<std::pair<int, int>, std::string> occupancyGrid;
	GameObjectManager _gameObjectManager1; //GameObject manager required to prevent memory leaks

	//Creating Sprite
	SpriteBackground* temp = new SpriteBackground();
	temp->SetPosition(0, 0, 320, 240);
	temp->Load("ArtAssets/Environment/Wall7.fw.png");
	temp->SetObjectID("obstacleDetected");
	_gameObjectManager1.Add("testing", temp);


	//Function - Make a new map class that places object 
	int x, y;
	sf::Image tempImage = temp->GetTexture().copyToImage();

	//Loop through pixels in texture
	for (int j = 0; j < tempImage.sf::Image::getSize().y; j++) {
		for (int i = 0; i < tempImage.sf::Image::getSize().x; i++) {

			if (tempImage.getPixel(i, j).a != 0) { //Assign to occupancy grid if non alpha values
				x = temp->GetPosition().x; - tempImage.sf::Image::getSize().x + i;
				y = temp->GetPosition().y; - tempImage.sf::Image::getSize().y + j;
				occupancyGrid[std::make_pair(x,y)] = temp->GetObjectID();
			}
		}
	}

	return;
}
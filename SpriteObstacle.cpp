#include "stdafx.h"
#include "SpriteObstacle.h"

//Constructor - sets sprite absolute location
SpriteObstacle::SpriteObstacle() 
{
	Load("ArtAssets/Environment/GrassTile.fw.png");
}

//Destructor
SpriteObstacle::~SpriteObstacle()
{

}

//GetPixelOccupancy - Returns the sprite occupancy of its 16x16 grid image.
//	input - pixel_occupancy[row][column]
void SpriteObstacle::GetPixelOccupancy(std::string pixel_occupancy[16][16])
{
	//Get image data
	sf::Image image_data = this->GetTexture().copyToImage();

	//Loop through pixels in texture
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i <16; i++) {
			
			if (image_data.getPixel(i, j).a != 0) { //if pixel doesn't contain alpha
				pixel_occupancy[j][i] = this->GetObjectID();
			}
			else {
				pixel_occupancy[j][i] = "NULL";
			}
		}
	}

}


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

//DrawToCanvas - Draws the object to the canvas according to the
//coordinates of the origin.
void SpriteObstacle::DrawToCanvas(float x_o, float y_o)
{


}

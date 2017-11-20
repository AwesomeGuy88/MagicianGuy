#include "stdafx.h"
#include "SpriteBackground.h"

//Constructor - sets sprite absolute location
SpriteBackground::SpriteBackground()
{
	Load("ArtAssets/Environment/GrassTile.fw.png");
}

//Destructor
SpriteBackground::~SpriteBackground()
{

}

//DrawToCanvas - Draws the object to the canvas according to the
//coordinates of the origin.
void SpriteBackground::DrawToCanvas(float x_o, float y_o)
{


}
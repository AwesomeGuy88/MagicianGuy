#include "stdafx.h"
#include "BackgroundObject.h"

//Constructor - sets sprite absolute location
BackgroundObject::BackgroundObject() 
{
	Load("ArtAssets/Environment/GrassTile.fw.png");
}

//Destructor
BackgroundObject::~BackgroundObject()
{

}

//DrawToCanvas - Draws the object to the canvas according to the
//coordinates of the origin.
void BackgroundObject::DrawToCanvas(float x_o, float y_o)
{


}
#include "stdafx.h"
#include "SpriteUser.h"


SpriteUser::SpriteUser()
{
	Load("ArtAssets/Mage/MageFront.png");
}


SpriteUser::~SpriteUser()
{

}


//Update() - Updates the SpriteUser according to time and UI
//		Considers - Keyboard inputs for movement (w,a,s,d)
void SpriteUser::Update(float elapsedTime, float x_o, float y_o)
{
	float fy_temp = this->y;
	float fx_temp = this->x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		fy_temp += elapsedTime * 40;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		fx_temp -= elapsedTime * 40;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		fy_temp -= elapsedTime * 40;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		fx_temp += elapsedTime * 40;
	}
	SetPosition(fx_temp, fy_temp, x_o, y_o);


}




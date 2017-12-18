#include "stdafx.h"
#include "SpriteUser.h"
#include "Map.h"
#include "Game.h"

SpriteUser::SpriteUser()
{
	Load("ArtAssets/Mage/MageFront.png");
}


SpriteUser::~SpriteUser()
{

}

/*
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
*/

//Update() - Updates the SpriteUser according to time and UI
// 1) Calculates movement based on - Keyboard inputs for movement and time passed (w,a,s,d)
// 2) Applies movement if position is not occupied
void SpriteUser::Update(float elapsedTime, float x_o, float y_o)
{

	//Applies movement like normal
	float fy_temp = this->y;
	float fx_temp = this->x;
	sf::Vector2f prev_position = sf::Vector2f(fx_temp, fy_temp);
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

	//Attempt to place to grid
	sf::Vector2f new_position = sf::Vector2f(fx_temp, fy_temp);
	Map* map = Game::GetMap();
	if (map->IsOccupied(this, new_position) == false) {
		map->RemoveFromGrid(this, prev_position);
		SetPosition(fx_temp, fy_temp, x_o, y_o);
		map->PlaceIntoGrid(this, new_position);
	}
	else {

		std::cout << "Failed" << std::endl;
	}
}

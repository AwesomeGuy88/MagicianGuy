#include "stdafx.h"
#include "VisibleGameObject.h"
#include "Game.h"

//Constructor - Sets flag of the object	without trigerring default constructor of isLoaded
VisibleGameObject::VisibleGameObject()
	: _isLoaded(false),
	_objectID("notSet")
{
}

//Destructor - Does nothing, no memory to return to heap or files to close
VisibleGameObject::~VisibleGameObject()
{

}

//Load - Loads specified image to the properties of the object and adjusts relevant
//		flags of the object
void VisibleGameObject::Load(std::string filename)
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
		//std::cout << "Image Load Success" << std::endl;

	}
}


//Draw - Draws the sprite to the window if conditions are safe.
void VisibleGameObject::Draw(sf::RenderWindow& renderWindow)
{
	float x_o = Game::GetOriginX();
	float y_o = Game::GetOriginY();
	float x_temp = x + x_o;	
	float y_temp = 480 - (y + y_o);

	if (_isLoaded)
	{
		if (x_temp > 0 && x_temp < Game::SCREEN_WIDTH)
		{
			if (y_temp > 0 && y_temp < Game::SCREEN_HEIGHT)
			{
				renderWindow.draw(_sprite);
			}
		}
	}
}

//Update - Update the image in response to user interaction.
void VisibleGameObject::Update(float elapsedTime, float x_o, float y_o)
{

}

//SetPosition - Sets the position data of the sprite relative to the origin
void VisibleGameObject::SetPosition(float x, float y, float x_o, float y_o)
{
	this->x = x;
	this->y = y;
	
	if (_isLoaded)
	{
		float x_temp = x + x_o;				//Increasing x corresponds to further to the right of the screen
		float y_temp = 480 - (y + y_o);		//Increasing y corresponds to further up the screen
		_sprite.setPosition(x_temp, y_temp);
	}
}

//SetObjectID - Set unique ID
void VisibleGameObject::SetObjectID(std::string ID)
{
	_objectID = ID;
}


//GetObjectID - Retrieve unique ID
std::string VisibleGameObject::GetObjectID()
{
	return _objectID;
}


//GetPosition - Returns actual coordinates.
sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		sf::Vector2f position(x, y);
		return position;
		//return _sprite.getPosition();
	}
	return sf::Vector2f();
}

//GetSprite - Retrieve sprite stored within class
sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

//IsLoaded - Retrieve _isloaded stored within class
bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

float VisibleGameObject::GetHeight() const
{
	return _sprite.getLocalBounds().height;
}

float VisibleGameObject::GetWidth() const
{
	return _sprite.getLocalBounds().width;
}

sf::Texture VisibleGameObject::GetTexture() const
{
	return _image;
}

//GetBoundingRect - Using sprite properties, calculates the dimensions of the bounding
//				rectangle and returns it.
sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	float width = GetWidth();
	float height = GetHeight();
	sf::Vector2f position = _sprite.getPosition();
	float xPos = position.x;
	float yPos = position.y;

	return sf::Rect<float>(
		xPos,
		yPos,
		width,
		height
		);
}




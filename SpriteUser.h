#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"
#include "SpriteObstacle.h"

class SpriteUser : public SpriteObstacle
{
public:
	SpriteUser();
	virtual ~SpriteUser();


	void Update(float elapsedTime, float x_o, float y_o);
};







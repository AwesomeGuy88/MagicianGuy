#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"

class SpriteUser : public VisibleGameObject
{
public:
	SpriteUser();
	virtual ~SpriteUser();


	void Update(float elapsedTime, float x_o, float y_o);
};







#pragma once
#include "VisibleGameObject.h"
//BackgroundObject - Basic object with no interactions

class SpriteBackground : public VisibleGameObject
{
public:
	SpriteBackground();
	virtual ~SpriteBackground();

	void DrawToCanvas(float x_o, float y_o);

private:
	float x_c;
	float y_c;
};





#pragma once
#include "VisibleGameObject.h"
//SpriteObstace - Basic object with interactions

class SpriteObstacle : public VisibleGameObject
{
public:
	SpriteObstacle();
	virtual ~SpriteObstacle();

	void DrawToCanvas(float x_o, float y_o);
private:
	float x_c;
	float y_c;
};





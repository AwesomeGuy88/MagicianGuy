#pragma once
#include "VisibleGameObject.h"
//BackgroundObject - Basic object with no interactions

class BackgroundObject : public VisibleGameObject
{
public:
	BackgroundObject();
	virtual ~BackgroundObject();

	void DrawToCanvas(float x_o, float y_o);

private:
	float x_c;
	float y_c;
};





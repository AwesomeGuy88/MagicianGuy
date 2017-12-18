#pragma once
#include "VisibleGameObject.h"
//SpriteObstace - Basic object with interactions

class SpriteObstacle : public VisibleGameObject
{
public:
	SpriteObstacle();
	virtual ~SpriteObstacle();

	virtual void GetPixelOccupancy(std::string pixel_occupancy[16][16]);
private:
};





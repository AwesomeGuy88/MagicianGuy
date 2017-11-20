#pragma once
#include "GameObjectManager.h"
#include <string>
#define MAX_MAP_ELEMENTS 500
#define MAX_OBSTACLE_ELEMENTS 500


class DataHandler
{
public:
	DataHandler();
	~DataHandler();

	void ExtractDataAndCreate(GameObjectManager* GM0, GameObjectManager* GM1, GameObjectManager* GM2, 
		float fOrigin_x, float fOrigin_y);

	int GetNumMapElements(int mode);
	void GetMapData(std::string szFileName0, std::string szFileName1);
	void CreateMap(GameObjectManager* _gameObjectManager, float fOrigin_x, float fOrigin_y, int mode);
	void PrintMapData(); //For Debugging

private:
	std::ifstream& OpenFile(std::string szFileName);

	struct mapElement {
		std::string szName;
		int nObjectId;
		float fX_pos;
		float fY_pos;
	};

	mapElement elements0[MAX_MAP_ELEMENTS] = {};
	int nNumMapElements0;

	mapElement elements1[MAX_OBSTACLE_ELEMENTS] = {};
	int nNumMapElements1;
	

};




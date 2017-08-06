#pragma once
#include <string>
#define MAX_MAP_ELEMENTS 200


class DataHandler
{
public:
	DataHandler();
	~DataHandler();
	
	int GetNumMapElements();
	void GetMapData(std::string szFileName);

	void PrintMapData(); //For Debugging

private:
	std::ifstream& OpenFile(std::string szFileName);

	struct mapElement {
		std::string szName;
		int nObjectId;
		float fX_pos;
		float fY_pos;
	};

	mapElement elements[MAX_MAP_ELEMENTS] = {};
	int nNumMapElements;
	

};




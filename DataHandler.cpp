#pragma once
#include "stdafx.h"
#include "DataHandler.h"
#include "SpriteBackground.h"
#include "GameObjectManager.h"
#include "SpriteObstacle.h"
#include "Map.h"
#include "Game.h"
#include <string>
#include <fstream>
#include <iostream> //For debugging


DataHandler::DataHandler() 
	: nNumMapElements0(0),
	nNumMapElements1(0)
{

}


DataHandler::~DataHandler()
{

}

void DataHandler::ExtractDataAndCreate(GameObjectManager* pGM0, GameObjectManager* pGM1, GameObjectManager* pGM2, float fOrigin_x, float fOrigin_y)
{

	GetMapData("map_data0.txt", "map_data1.txt");
	CreateMap(pGM0, fOrigin_x, fOrigin_y, 0);
	CreateMap(pGM1, fOrigin_x, fOrigin_y, 1);
}

int DataHandler::GetNumMapElements(int mode)
{
	if (mode == 1) {
		return nNumMapElements0;
	}
	else {
		return nNumMapElements1;
	}
}

//OpenFile - Open stream to file safely
std::ifstream& DataHandler::OpenFile(std::string szFileName)
{
	std::ifstream* pFileStream = 0;
	while (1)
	{
		//Open file for reading
		pFileStream = new std::ifstream(szFileName.c_str());

		//Safeguard against failure
		if (pFileStream->good())
		{
			pFileStream->seekg(0);
			break;
		}
		delete pFileStream;
	}
	return *pFileStream;
}

//GetMapData - Extracts data from external files
//		In the form of: 1) Name  2) ObjectID  3) Position
void DataHandler::GetMapData(std::string szFileName0, std::string szFileName1)
{
	int nECount = 0;
	//Open files for reading
	std::ifstream& pFileStream = OpenFile(szFileName0);
	std::ifstream& pFileStream1 = OpenFile(szFileName1);


	//Background Elements
	while (!pFileStream.eof())
	{
		pFileStream >> elements0[nECount].szName;
		pFileStream >> elements0[nECount].nObjectId;
		pFileStream >> elements0[nECount].fX_pos;
		pFileStream >> elements0[nECount].fY_pos;

		//Stop if file read failed
		if (pFileStream.fail())
		{
			break;
		}

		nECount++;
	}
	nNumMapElements0 = nECount;


	//Obstacle Elements
	nECount = 0;
	while (!pFileStream1.eof())
	{
		pFileStream1 >> elements1[nECount].szName;
		pFileStream1 >> elements1[nECount].nObjectId;
		pFileStream1 >> elements1[nECount].fX_pos;
		pFileStream1 >> elements1[nECount].fY_pos;

		//Stop if file read failed
		if (pFileStream1.fail())
		{
			break;
		}

		nECount++;
	}
	nNumMapElements1 = nECount;
}

//CreateMap - Creates objects according to data
//		mode - (0) Background, (1) Obstacles
void DataHandler::CreateMap(GameObjectManager* _gameObjectManager, float fOrigin_x, float fOrigin_y, int mode)
{

	if (mode == 0) {	//Background
		for (int i = 0; i < nNumMapElements0; i++)
		{
			SpriteBackground* temp = new SpriteBackground();

			switch (elements0[i].nObjectId)
			{
			case 0:
				temp->Load("ArtAssets/Environment/GrassTile.fw.png");
				break;
			case 1:
				temp->Load("ArtAssets/Environment/ConcreteTile.fw.png");
				break;
			default:
				break;
			}

			temp->SetPosition(elements0[i].fX_pos, elements0[i].fY_pos, fOrigin_x, fOrigin_y);
			_gameObjectManager->Add(elements0[i].szName, temp);

		}
	}
	else if(mode == 1) {	//Obstacles
		Map* map = Game::GetMap();
		for (int i = 0; i < nNumMapElements1; i++)
		{
			SpriteObstacle* temp = new SpriteObstacle();

			switch (elements1[i].nObjectId)
			{
			case 0:
				temp->Load("ArtAssets/Environment/Wall1.fw.png");
				temp->SetObjectID(elements1[i].szName);
				break;
			case 1:
				temp->Load("ArtAssets/Environment/Wall2.fw.png");
				temp->SetObjectID(elements1[i].szName);
				break;
			default:
				break;
			}

			temp->SetPosition(elements1[i].fX_pos, elements1[i].fY_pos, fOrigin_x, fOrigin_y);
			_gameObjectManager->Add(elements1[i].szName, temp);
			sf::Vector2f init_position(elements1[i].fX_pos, elements1[i].fY_pos);
			map->PlaceIntoGrid(temp, init_position);

		}
	}

}

void DataHandler::PrintMapData()
{
	for (int i = 0; i < nNumMapElements1; i++)
	{
		std::cout << "Map Data: " << std::endl
			<< "Element " << i << ":"
			<< elements1[i].szName << ", "
			<< elements1[i].nObjectId << ", "
			<< elements1[i].fX_pos << ", "
			<< elements1[i].fY_pos << ", "
			<< std::endl;
	}
}
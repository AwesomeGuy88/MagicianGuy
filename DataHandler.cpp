#pragma once
#include "stdafx.h"
#include "DataHandler.h"
#include <string>
#include <fstream>
#include <iostream> //For debugging


DataHandler::DataHandler() 
	: nNumMapElements(0)
{

}


DataHandler::~DataHandler()
{

}

int DataHandler::GetNumMapElements()
{
	return nNumMapElements;
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
void DataHandler::GetMapData(std::string szFileName)
{
	int nECount = 0;
	//Open file for reading
	std::ifstream& pFileStream = OpenFile(szFileName);


	//Read the file
	while (!pFileStream.eof())
	{
		pFileStream >> elements[nECount].szName;
		pFileStream >> elements[nECount].nObjectId;
		pFileStream >> elements[nECount].fX_pos;
		pFileStream >> elements[nECount].fY_pos;


		//Stop if file read failed
		if (pFileStream.fail())
		{
			break;
		}

		nECount++;
	}
	nNumMapElements = nECount;
}

void DataHandler::PrintMapData()
{
	for (int i = 0; i < nNumMapElements; i++)
	{
		std::cout << "Map Data: " << std::endl
			<< "Element " << i << ":"
			<< elements[i].szName << ", "
			<< elements[i].nObjectId << ", "
			<< elements[i].fX_pos << ", "
			<< elements[i].fY_pos << ", "
			<< std::endl;
	}
}
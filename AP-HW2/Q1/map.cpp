#include "map.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Map::Map(int n) {
	mapSize = static_cast<int>(n);
	for (size_t i{}; i < mapSize; i++)
	{
		mainMap.push_back(std::vector<int>());
		for (size_t j{}; j < mapSize; j++)
		{
			randNum = (std::rand() % 99) + 1;
			mainMap[i].push_back(randNum);
		}
	}
	std::cout << "Map was created!" << std::endl;

	// Initialzing final Route by " "
	for (size_t i{}; i < mapSize; i++)
	{
		finalRoute.push_back(std::vector<char>());
		for (size_t j{}; j < mapSize; j++)
		{
			finalRoute[i].push_back(' ');
		}
	}
	finalRoute[0][0] = '*'; // Setting stating point to "*"
	
	
}

void Map::showMap() {
	std::cout << "The map is: " << std::endl;
	for (size_t i{}; i < mapSize; i++)
	{
		for (size_t j{}; j < mapSize; j++)
		{
			std::cout << std::setw(2) << mainMap[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int Map::findRoute() {
	std::cout << "Trying to find route..." << std::endl;

	
	
	return sizeof(finalRoute);
}

void Map::showRoute() {
	std::cout << "The route is: " << std::endl;
	for (size_t i{}; i < mapSize; i++)
	{
		for (size_t j{}; j < mapSize; j++)
		{
			std::cout << std::setw(2) << finalRoute[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

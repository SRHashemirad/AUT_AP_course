#include "map.h"
#include <iostream>

Map::Map(int n) {
	mapSize = static_cast<int>(n);
	for (size_t i{}; i < mapSize; i++)
	{
		mainMap.push_back(std::vector<int>());
		for (size_t j{}; j < mapSize; j++)
		{
			mainMap[i].push_back(10);
		}
	}
	std::cout << "Map was created!" << std::endl;
}

void Map::showMap() {
	for (size_t i{}; i < mapSize; i++)
	{
		for (size_t j{}; j < mapSize; j++)
		{
			std::cout << mainMap[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

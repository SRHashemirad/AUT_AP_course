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

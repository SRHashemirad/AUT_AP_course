#include "map.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

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

	// Initialzing final Route by "-"
	for (size_t i{}; i < mapSize; i++)
	{
		finalRoute2D.push_back(std::vector<char>());
		for (size_t j{}; j < mapSize; j++)
		{
			finalRoute2D[i].push_back('-');
		}
	}
	finalRoute2D[0][0] = '*'; // Setting stating point to "*"

	// Initialzing final Route 3D by "-"
	for (size_t i{}; i < mapSize; i++)
	{
		finalRoute3D.push_back(std::vector<char>());
		for (size_t j{}; j < mapSize; j++)
		{
			finalRoute3D[i].push_back('-');
		}
	}
	finalRoute3D[0][0] = '*'; // Setting stating point to "*"
	
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

int Map::findRoute2D() {
	std::cout << "Trying to find route..." << std::endl;
	currentX = 0;
	currentY = 0;
	
	while (!(currentX == mapSize-1 && currentY == mapSize-1))
	{
		if (currentY == mapSize-1)
		{
			dDiff = std::abs(mainMap[currentX+1][currentY] - mainMap[currentX][currentY]);
			sumDiff += dDiff;
			direct = 2;
			currentX++;
		}
		else if (currentX == mapSize-1)
		{
			rDiff = std::abs(mainMap[currentX][currentY+1] - mainMap[currentX][currentY]);
			sumDiff += rDiff;
			direct = 1;
			currentY++;
		}
		else
		{
			rDiff = std::abs(mainMap[currentX][currentY+1] - mainMap[currentX][currentY]);
			dDiff = std::abs(mainMap[currentX+1][currentY] - mainMap[currentX][currentY]);
		}
		if(!direct)
		{
			if(rDiff <= dDiff)
			{
				sumDiff += rDiff;
				direct = 1;
				currentY++;
			}
			else
			{
				sumDiff += dDiff;
				direct = 2;
				currentX++;
			}
		}

		direct = 0;
		
        //std::cout << "direct is: " << direct << std::endl;
		//finalRoute2D[currentX][currentY] = '*';
		//std::cout << "X is " << currentX << ", Y is " << currentY << std::endl;
	}
	
	return sumDiff;
}

int Map::findRoute3D() {
	std::cout << "Trying to find route..." << std::endl;
	currentX = 0;
	currentY = 0;
	
	while (!(currentX == mapSize-1 && currentY == mapSize-1))
	{
		if (currentY == mapSize-1)
		{
			dDiff = std::abs(mainMap[currentX+1][currentY] - mainMap[currentX][currentY]);
			sumDiff += dDiff;
			direct = 2;
			currentX++;
		}
		else if (currentX == mapSize-1)
		{
			rDiff = std::abs(mainMap[currentX][currentY+1] - mainMap[currentX][currentY]);
			sumDiff += rDiff;
			direct = 1;
			currentY++;
		}
		else
		{
			rDiff = std::abs(mainMap[currentX][currentY+1] - mainMap[currentX][currentY]);
			dDiff = std::abs(mainMap[currentX+1][currentY] - mainMap[currentX][currentY]);
			cDiff = std::abs(mainMap[currentX+1][currentY+1] - mainMap[currentX][currentY]);
		}
		if(!direct)
		{
			if(rDiff <= dDiff && rDiff <= cDiff)
			{
				sumDiff += rDiff;
				direct = 1;
				currentY++;
			}
			else if (dDiff <= cDiff)
			{
				sumDiff += dDiff;
				direct = 2;
				currentX++;
			}
			else
			{
				sumDiff += cDiff;
				direct = 3;
				currentX++;
				currentY++;
			}
		}

		direct = 0;
		
        std::cout << "direct is: " << direct << std::endl;
		finalRoute3D[currentX][currentY] = '*';
		std::cout << "X is " << currentX << ", Y is " << currentY << std::endl;
	}
	
	return sumDiff;
}

void Map::showRoute(size_t dir) {
	std::cout << "The route is: " << std::endl;
	if(dir == 2)
	{
		for (size_t i{}; i < mapSize; i++)
		{
			for (size_t j{}; j < mapSize; j++)
			{
				std::cout << std::setw(2) << finalRoute2D[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else if (dir == 3)
	{
		for (size_t i{}; i < mapSize; i++)
		{
			for (size_t j{}; j < mapSize; j++)
			{
				std::cout << std::setw(2) << finalRoute3D[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "Just 2 or 3!!" << std::endl;
	}
}

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>


class Map
{

public:
	// Methods
	Map (int);
	void showMap();
	int findRoute2D();
	int findRoute3D();
	void showRoute(size_t); // For 2 directions, call showRoute(2) ...
	                        // ...and for 3 directions, call showRoute(3)

	void generateAll();
	void calculateAll();
	size_t findMinRoute();
	void showMinRoute();
	
	//Variables
	size_t mapSize{};
	std::vector < std::vector <int> > mainMap;
	int randNum{}; // For generate random numbers in map.
	std::vector < std::vector <char> > finalRoute2D;
	std::vector < std::vector <char> > finalRoute3D;
	std::vector < std::vector <char> > finalMinRoute;
	std::vector < std::vector <int> > heightDiff; // To store height Differences

	size_t currentX{};
	size_t currentY{};

	size_t rDiff{}; // Right difference
	size_t dDiff{}; // Down difference
	size_t cDiff{}; // Corner difference
	
	size_t direct{}; // To save direction...
	                 // ...(0 for reset mode; 1 for right; 2 for down; 3 for corner)

	size_t sumDiff{};

	std::vector <std::string> allPos {};
	std::vector <size_t> allSumDiff {};

	std::string minRoute{};
};
#endif

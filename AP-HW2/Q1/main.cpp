#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "map.h"

int main(int argc, char const *argv[])
{
	//srand(static_cast<int>(time(0))); //Generating real random numbers every exection.

	Map map{10};
	map.showMap();

	//Part I
	int sumDiff2D{map.findRoute2D()};
	std::cout << "sumDiff is " << sumDiff2D << std::endl;
	map.showRoute(2);

	//Part II
	int sumDiff3D{map.findRoute3D()};
	std::cout << "sumDiff is " << sumDiff3D << std::endl;
	map.showRoute(3);

	//Part III
	map.generateAll();
	map.calculateAll();
	std::cout << "The min cost is: "
			  << map.findMinRoute()
			  << std::endl
			  << "... and the route is: "
			  << std::endl;
	map.showMinRoute();
	return 0;
}


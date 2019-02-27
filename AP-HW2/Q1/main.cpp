#include <iostream>
#include <vector>
#include <ctime>
#include "map.h"

int main(int argc, char const *argv[])
{
	//srand(static_cast<int>(time(0))); //Generating real random numbers every exection.

	Map map{10};
	map.showMap();
	int sumDiff{map.findRoute3D()};
	std::cout << "sumDiff is " << sumDiff << std::endl;
	map.showRoute(3);
	return 0;
}


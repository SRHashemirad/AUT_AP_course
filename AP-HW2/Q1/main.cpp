#include <iostream>
#include <vector>
#include <ctime>
#include "map.h"

int main(int argc, char const *argv[])
{
	srand(static_cast<int>(time(0))); //Generating real random numbers every exection.
	
	Map map{3};
	map.showMap();
	map.findRoute();
	map.showRoute();
	return 0;
}


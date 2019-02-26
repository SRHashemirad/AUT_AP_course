#include <vector>


class Map
{

public:
	// Methods
	Map (int);
	void showMap();
	int findRoute();
	void showRoute();

	//Variables
	size_t mapSize{};
	std::vector < std::vector <int> > mainMap;
	int randNum{}; // For generate random numbers in map.
	std::vector < std::vector <char> > finalRoute;
	std::vector < std::vector <int> > heightDiff; // To store height Differences
};

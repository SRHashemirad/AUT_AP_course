#include <vector>
class Map
{
public:
	// Methods
	Map (int);
	void showMap();

	//Variables
	size_t mapSize;
	std::vector < std::vector <int> > mainMap;
};

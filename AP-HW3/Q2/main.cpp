#include <iostream>
#include "myVec.h"

int main() {

	myVec vec{};
//	std::cout << vec.capacity <<" OK!" << std::endl;
	vec.push_back(10);
//	std::cout << vec.capacity <<" OK!" << std::endl;
	vec.push_back(20);
	for (int i{}; i<100; i++)
	{
		vec.push_back(i);
	}
	vec.show();
	return 0;
}

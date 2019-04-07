#include <iostream>
#include "myVec.h"

int main() {

	myVec vec{};
	for(size_t i{}; i < 50; i++)
	{
		//std::cout << "iter " << i << ": ";
		vec.push_back(i);
		/*std::cout << "Cap is: "
				  << vec.capacity
				  << ", Size is: "
				  << vec.size
				  << std::endl;*/
	}

	vec.show();
	
	for(size_t i{}; i < 20; i++)
	{
		//std::cout << "iter " << i << ": ";
		vec.pop_back();
		/*std::cout << "Cap is: "
				  << vec.capacity
				  << ", Size is: "
				  << vec.size
				  << std::endl;*/
	}

	vec.show();
	
	for(size_t i{}; i < 30; i++)
	{
		//std::cout << "iter " << i << ": ";
		vec.push_back(i);
		/*std::cout << "Cap is: "
				  << vec.capacity
				  << ", Size is: "
				  << vec.size
				  << std::endl;*/
	}

	vec.show();
	
	return 0;
}

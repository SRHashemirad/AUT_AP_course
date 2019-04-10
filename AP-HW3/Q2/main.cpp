#include <iostream>
#include "myVec.h"
#include <utility>

using namespace std::rel_ops;

int main() {

	myVec vec{};
	myVec vec2{std::move(vec)};
	vec.show();
/*
	myVec vec2{vec};
	
	for(size_t i{1}; i < 6; i++)
	{
		vec.push_back(i);
		//	vec2.push_back(i);
	}

	myVec vec2{vec};

	for(size_t i{1}; i < 6; i++)
	{
		//vec.push_back(i);
		vec2.push_back(i);
	}

	std::cout << vec.innerSum(vec2) << std::endl;
	std::cout << vec2.innerProduct(vec) << std::endl;

	std::cout << (vec < vec2) << std::endl;
	std::cout << (vec == vec2) << std::endl;

	vec.show();
	vec2.show();

	vec = myVec();
	vec.show();

	std::cout << vec << std::endl;
*/
	return 0;
}

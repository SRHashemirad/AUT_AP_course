#include "libVec.h"
#include <iostream>

LibVec::LibVec() {
	std::cout << "LibVec created!" << std::endl;
}

long long LibVec::counter(long long n) {
	long long sum{};
	for (long long i{}; i < n; i++)
	{
		vec.push_back(i);
		sum += i;
	}
	return sum;
}

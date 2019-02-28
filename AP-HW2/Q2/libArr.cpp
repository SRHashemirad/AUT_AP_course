#include "libArr.h"
#include <iostream>

LibArr::LibArr() {
	std::cout << "LibArr created!" << std::endl;
}

long long LibArr::counter(long long n) {

	long long sum{};
	long long arr[n]{};
	
	for (long long i{}; i < n; i++)
	{
		arr[i] = i;
		sum += i;
	}
	return sum;
}

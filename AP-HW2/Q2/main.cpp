#include <iostream>
#include <time.h>
#include "libVec.h"
#include "libArr.h"


int main() {

	long long maxCount{100LL};
	long int start_s{clock()};
	
	LibVec vec{};
	std::cout << vec.counter(maxCount) << std::endl;

	long int stop_s{clock()};
	std::cout << "time: "
			  << (stop_s - start_s) / static_cast<double>(CLOCKS_PER_SEC) * 1000
			  << " ms"
			  << std::endl;
	
	start_s = clock();
	
	LibArr arr{};
	std::cout << arr.counter(maxCount) << std::endl;

	stop_s = clock();
	std::cout << "time: "
			  << (stop_s - start_s) / static_cast<double>(CLOCKS_PER_SEC) * 1000
			  << " ms"
			  << std::endl;
	
	return 0;
}

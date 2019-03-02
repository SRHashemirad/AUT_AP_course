#include <iostream>
#include <ctime>
#include <iomanip>
#include "libVec.h"
#include "libArr.h"

typedef long long (LibVec::*pointer_to_vec_counter) (long long);
typedef long long (LibArr::*pointer_to_arr_counter) (long long);

template<typename T1, typename T2>
long long runTime(T1, T2, long long n);

int main() {

	LibVec vec{};
	LibArr arr{};

	
	pointer_to_vec_counter ptrVecCount = &LibVec::counter;
	pointer_to_arr_counter ptrArrCount = &LibArr::counter;

	std::cout << "The run times are in micro secondes!" << std::endl;
	std::cout << std::setw(9) << "   Size  " << " | "
			  << std::setw(9) << "  Vector " << " | "
			  << std::setw(9) << "  Array  "
			  << std::endl
			  << std::setw(36) << "------------------------------------"
			  << std::endl;
	
	for (long long i{1LL}; i <= 1000000LL; i *= 10LL)
	{
		std::cout << std::setw(9) << i << " | "
			  << std::setw(9) << runTime(vec, ptrVecCount, i) << " | "
			  << std::setw(9) << runTime(arr, ptrArrCount, i)
			  << std::endl
			  << std::setw(36) << "------------------------------------"
			  << std::endl;
	}

	return 0;
}


template<typename T1, typename T2>
long long runTime(T1 obj, T2 ptrCounter, long long n) {
	long int start_s{clock()};
	(obj.*ptrCounter)(n);
	long int stop_s{clock()};	
	return (stop_s - start_s) / static_cast<double>(CLOCKS_PER_SEC) * 10000000;
}

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

//	long long (LibVec::*pointer_to_vec_counter) (long long) = &LibVec::counter;
//	long long (LibArr::*pointer_to_arr_counter) (long long) = &LibArr::counter;
	
	pointer_to_vec_counter ptrVecCount= &LibVec::counter;
	pointer_to_arr_counter ptrArrCount= &LibArr::counter;
	
	
	for (long long i{1}; i < 1000000; i *= 10)
	{
		std::cout << "Vector/Array size is: "
				  << i
				  << std::endl;
		std::cout <<  "runTime for vector class is: "
				  << runTime(vec, ptrVecCount, i)
				  << " us"
				  << std::endl
				  << "runTime for array class is: "
				  << runTime(arr, ptrArrCount, i)
				  << " us"
				  << std::endl
				  << std::endl;
	}
/*
	long long maxCount{1000000LL};
	
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
*/
	return 0;
}


template<typename T1, typename T2>
long long runTime(T1 obj, T2 ptrCounter, long long n) {
	long int start_s{clock()};
	(obj.*ptrCounter)(n);
	long int stop_s{clock()};	
	return (stop_s - start_s) / static_cast<double>(CLOCKS_PER_SEC) * 10000000;
}

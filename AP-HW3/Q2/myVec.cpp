#include "myVec.h"

myVec::myVec() {
	std::cout << "myVec default constructor" << std::endl;

	//size and capacity initalization
	size = 0;
	capacity = 1;

	//reserve memory for 1 int
	arr = new int[capacity];
}


myVec::~myVec() {
	std::cout << "I'm dying..." << std::endl;
	delete[] arr;
}

void myVec::show() {
	std::cout << "The vector is: ";
	for (long int i{}; i < size; i++)
		std::cout << std::setw(4) << arr[i];
	std::cout << std::endl;
}

void myVec::push_back(int newNum)
{
	size++;

	//Checking if capacity needs to be larger or not
	
	long int log2OfSize{static_cast<long int>(std::log2(size))};

	if(size == (1 << log2OfSize))
	{
		//copy old data to tempArr
		int* tempArr{new int [size-1]};
		for (long int i{}; i < size-1; i++)
		{
			tempArr[i] = arr[i];
		}

		std::cout << "capacity doubled!" << std::endl;
		capacity *= 2;

		arr = new int [capacity];
		for (long int i{}; i < size-1; i++)
		{
			arr[i] = tempArr[i];
		}
		delete[] tempArr;
	}
	
	arr[size-1] = newNum;
}

#include "myVec.h"

myVec::myVec() {
	std::cout << "myVec default constructor" << std::endl;

	//size and capacity initalization
	size = 0;
	capacity = 1;

	//reserve memory for 1 int
	arr = new int[capacity];
}

myVec::myVec(const myVec& vec) {
	std::cout << "copy constructor" << std::endl;
	size = vec.size;
	capacity = vec.capacity;

	arr = new int [capacity];
	for (unsigned long i{}; i < capacity; i++)
	{
		arr[i] = vec.arr[i];
	}
}

myVec::myVec(myVec&& vec) {
	std::cout << "move constructor" << std::endl;
	size = vec.size;
	capacity = vec.capacity;
	arr = vec.arr;
	vec.arr = nullptr;
}


myVec::~myVec() {
	std::cout << "I'm dying..." << std::endl;
	delete[] arr;
}

void myVec::show() const {
	std::cout << "The vector is: ";
	for (unsigned long i{}; i < size; i++)
		std::cout << std::setw(4) << arr[i];
	std::cout << std::endl;
}

void myVec::push_back(int newNum)
{
	size++;

	//Checking if capacity needs to be larger or not
	
	unsigned long log2OfSize{static_cast<unsigned long>(std::log2(size))};

	if (size == static_cast<unsigned long>(1 << log2OfSize))
	{
		//copy old data to tempArr
		int* tempArr{new int [size-1]};
		for (unsigned long i{}; i < size-1; i++)
		{
			tempArr[i] = arr[i];
		}

		std::cout << "capacity doubled!" << std::endl;
		capacity *= 2;

		arr = new int [capacity];
		for (unsigned long i{}; i < size-1; i++)
		{
			arr[i] = tempArr[i];
		}
		delete[] tempArr;
	}
	
	arr[size-1] = newNum;
}

void myVec::pop_back() {

	//If size is zero or smaller, we can not pop_back the array!
	if (size < 1) 
	{
		std::cout << "pop_back is not possible!" << std::endl;
		return;
	}
	
	arr[size-1] = 0;
	
	//Checking if capacity needs to be smaller or not
	
	unsigned long log2OfSize{static_cast<unsigned long>(std::log2(size))};

	if (size == static_cast<unsigned long>(1 << log2OfSize))
	{
		//copy old data to tempArr
		int* tempArr{new int [size-1]};
		for (unsigned long i{}; i < size-1; i++)
		{
			tempArr[i] = arr[i];
		}

		std::cout << "capacity halved!" << std::endl;
		capacity /= 2;

		arr = new int [capacity];
		for (unsigned long i{}; i < size-1; i++)
		{
			arr[i] = tempArr[i];
		}
		delete[] tempArr;
	}

	size--;
}


unsigned long myVec::innerSum(const myVec& vec) const {
	if (size != vec.size)
	{
		std::cout << "Two vectors must have same size!" << std::endl;
		return 0;
	}

	long int sum{};
	for (unsigned long i{}; i < size; i++)
	{
		sum += (arr[i] + vec.arr[i]);
	}
	return sum;
}


unsigned long myVec::innerProduct(const myVec& vec) const {
	if (size != vec.size)
	{
		std::cout << "Two vectors must have same size!" << std::endl;
		return 0;
	}

	long int product{1};
	for (unsigned long i{}; i < size; i++)
	{
		product *= (arr[i] * vec.arr[i]);
	}
	return product;
}

bool myVec::operator<(const myVec& vec) const {
	return size < vec.size; 
}

bool myVec::operator==(const myVec& vec) const {
	return size == vec.size;
}


myVec& myVec::operator=(const myVec& vec) {
	std::cout << "operator = copy version" << std::endl;
	if(this == &vec)
		return *this;
	size = vec.size;
	capacity = vec.capacity;
	delete[] arr; //must be used becuase when this operator was called,
	              //...the object has the arr!
	arr = new int [capacity];
	for (unsigned long i{}; i < capacity; i++)
	{
		arr[i] = vec.arr[i];
	}
	return *this;
}

myVec& myVec::operator=(myVec&& vec) {
	std::cout << "operator = move version" << std::endl;
	if(this == &vec)
		return *this;
	size = vec.size;
	capacity = vec.capacity;
	delete[] arr;
	arr = vec.arr;
	vec.arr = nullptr; //important!!
	return *this;
}

myVec myVec::operator+(const myVec& vec) {
	if (size != vec.size)
	{
		std::cout << "Two vectors must have same size!" << std::endl;
		return *this;
	}

	myVec copy{*this};
	for (unsigned long i{}; i < size; i++)
	{
		copy.arr[i] = (arr[i] + vec.arr[i]);
	}
	return copy;
}

std::ostream& operator<<(std::ostream& os, myVec vec) {
	os << vec.size;
	return os;
}

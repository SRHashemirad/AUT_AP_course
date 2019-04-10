#ifndef MY_VEC_H
#define MY_VEC_H

#include <iostream>
#include <iomanip>
#include <cmath> //pow

class myVec;
std::ostream& operator<<(std::ostream& os, myVec vec);

class myVec{
public:
	myVec();
	~myVec();

	myVec(const myVec&);
	myVec(myVec&&);

	void show() const;
	void push_back(int);
	void pop_back();
	long int innerSum(const myVec&) const;
	long int innerProduct(const myVec&) const;

	bool operator<(const myVec&) const;
	bool operator==(const myVec&) const;
	myVec& operator=(const myVec&);
	myVec& operator=(myVec&&);
	myVec operator+(const myVec& vec);

	long int size;
	long int capacity;
//private:
	int* arr;
};



#endif

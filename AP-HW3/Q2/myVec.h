#ifndef MY_VEC_H
#define MY_VEC_H

#include <iostream>
#include <iomanip>
#include <cmath> //pow

class myVec{
public:
	myVec();
	~myVec();
	void show();
	void push_back(int);
	void pop_back();
	
	long int size;
	long int capacity;
//private:
	int* arr;
};



#endif

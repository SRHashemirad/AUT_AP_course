#ifndef MYVEC_H
#define MYVEC_H

#include <iostream>
#include <iomanip>
#include <cmath> //pow

class myVec{
public:
	myVec();
	~myVec();
	void show();
	void push_back(int);
	
	long int size;
	long int capacity;
//private:
	int* arr;
};



#endif

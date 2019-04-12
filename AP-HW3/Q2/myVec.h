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
	unsigned long innerSum(const myVec&) const;
	unsigned long innerProduct(const myVec&) const;

	bool operator<(const myVec&) const;
	bool operator==(const myVec&) const;
	myVec& operator=(const myVec&);
	myVec& operator=(myVec&&);
	myVec operator+(const myVec& vec);

	unsigned long size;
	unsigned long capacity;
//private:
	int* arr;
};



#endif

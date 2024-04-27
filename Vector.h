#pragma once

#include <initializer_list>

class Vector {
public:
	Vector(int s);
	Vector(std::initializer_list<double>);
	~Vector();
	double& operator[](int i);
	int size();

private:
	double* elem;  
	int sz;    
};
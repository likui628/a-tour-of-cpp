#include "Vector.h"
#include <algorithm>

Vector::Vector(int s) : elem{ new double[s] }, sz{ s } {}

Vector::Vector(std::initializer_list<double> lst)
	:elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
	std::copy(lst.begin(), lst.end(), elem);
}

Vector::~Vector()
{
	delete[] elem;
}

double& Vector::operator[](int i) {
	return elem[i];
}

int Vector::size() {
	return sz;
}
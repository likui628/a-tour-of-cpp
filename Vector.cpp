#include "Vector.h"
#include <algorithm>

Vector::Vector(int s) : elem{ new double[s] }, sz{ s } {}

Vector::Vector(std::initializer_list<double> lst)
	:elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
	std::copy(lst.begin(), lst.end(), elem);
}

Vector::Vector(const Vector& other) :elem{ new double[other.sz] }, sz{ other.sz }
{
	for (int i = 0; i < other.sz; ++i) {
		elem[i] = other[i];
	}
}

Vector::Vector(Vector&& other) noexcept :elem{ other.elem }, sz{ other.sz }
{
	other.elem = nullptr;
	other.sz = 0;
}

Vector::~Vector()noexcept
{
	delete[] elem;
}

Vector& Vector::operator=(const Vector& other)
{
	double* p = new double[other.sz];
	for (int i = 0; i < other.sz; ++i) {
		p[i] = other[i];
	}
	delete[] elem;
	elem = p;
	sz = other.sz;
	return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this != &other) {
		delete[] elem;
		elem = other.elem;
		sz = other.sz;
		other.elem = nullptr;
		other.sz = 0;
	}
	return *this;
}

double& Vector::operator[](int i) {
	return elem[i];
}

const double& Vector::operator[](int i) const
{
	return elem[i];
}

int Vector::size() {
	return sz;
}
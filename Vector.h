#pragma once

#include <initializer_list>

class Vector {
public:
	Vector(int s);
	Vector(std::initializer_list<double>);
	Vector(const Vector&);
	Vector(Vector&&) noexcept;
	~Vector()noexcept;

	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&) noexcept;
	double& operator[](int i);
	const double& operator[](int i)const;
	int size();

private:
	double* elem;
	int sz;
};
#include "Vector.h"
#include <memory>

template<typename T>
Vector<T>::Vector() :elem{ nullptr }, space{ nullptr }, last{ nullptr }
{
}

template<typename T>
Vector<T>::Vector(int n) : elem{ alloc.allocate(n) }, space{ elem + n }, last{ elem + n }
{
	for (T* p = elem; p != space; ++p) {
		alloc.construct(p, T());
	}
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
{
}

template<typename T>
Vector<T>::~Vector() noexcept
{
}

//template<typename T>
//Vector& Vector<T>::operator=(const Vector& other)
//{
//	// TODO: insert return statement here
//}
//
//template<typename T>
//Vector& Vector<T>::operator=(Vector&& other) noexcept
//{
//	// TODO: insert return statement here
//}

template<typename T>
int Vector<T>::size()
{
	return space - elem;
}

template<typename T>
int Vector<T>::capacity()
{
	return last - elem;
}

template<typename T>
void Vector<T>::reserve(int sz)
{
}

template<typename T>
void Vector<T>::push_back(T& t)
{
}

template<typename T>
void Vector<T>::push_back(T&& t)
{
}

#pragma once
#include <memory>

template<typename T>
class Vector {
	std::allocator<T> alloc;
	T* elem;									// pointer to first element
	T* space;								// pointer to first unused slot
	T* last;									// pointer to last slot

public:
	Vector();
	Vector(int n);
	Vector(const Vector& other);

	Vector(Vector&& other) noexcept;

	~Vector()noexcept;

	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;
	T& operator[](int i);

	size_t size()const;
	size_t capacity()const;

	void reserve(int newsz);
	void push_back(const T& t);
	void push_back(T&& t);
};

template<typename T>
inline Vector<T>::Vector() :elem{ nullptr }, space{ nullptr }, last{ nullptr }
{
}

template<typename T>
inline Vector<T>::Vector(int n)
	: elem{ alloc.allocate(n) },
	space{ elem + n },
	last{ elem + n }
{
	std::uninitialized_fill(elem, space, T());
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
	:elem{ alloc.allocate(other.capacity()) },
	space{ elem + other.size() },
	last{ elem + other.capacity() }
{
	std::uninitialized_copy(other.elem, other.space, elem);
}

template<typename T>
inline Vector<T>::Vector(Vector&& other) noexcept :
	elem{ other.elem }, space{ other.space }, last{ other.last }
{
	other.elem = other.space = other.last = nullptr;
}

template<typename T>
inline Vector<T>::~Vector() noexcept
{
	// First, ensure all objects have their destructors called
	std::destroy(elem, last);
	// Then, free the entire block of memory
	alloc.deallocate(elem, last - elem);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != other) {
		Vector temp(other);
		std::swap(*this, temp);
	}
	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	std::swap(elem, other.elem);
	std::swap(space, other.space);
	std::swap(last, other.last);
	return *this;
}

template<typename T>
inline T& Vector<T>::operator[](int i) {
	return *(elem + i);
}

template<typename T>
inline size_t Vector<T>::size()const
{
	return static_cast<size_t>(space - elem);
}

template<typename T>
inline size_t Vector<T>::capacity() const
{
	return static_cast<size_t>(last - elem);
}

template<typename T>
inline void Vector<T>::reserve(int newsz)
{
	if (newsz > capacity()) {
		T* newelem = alloc.allocate(newsz);
		T* newspace = std::uninitialized_copy(
			std::make_move_iterator(elem),
			std::make_move_iterator(space),
			newelem);

		// Manually call the destructor for each object in the original array
		for (T* p = elem; p != space; ++p) {
			p->~T();
		}
		// Deallocate the old space
		alloc.deallocate(elem, last - elem);

		elem = newelem;
		space = newspace;
		last = elem + newsz;
	}
}

template<typename T>
inline void Vector<T>::push_back(const T& t)
{
	if (space == last) {
		reserve(capacity() == 0 ? 8 : 2 * capacity());
	}
	// Use placement new to construct an object in allocated, uninitialized memory.
	// https://en.cppreference.com/w/cpp/language/new#Placement_new
	new (space)T(t);
	++space;
}

template<typename T>
inline void Vector<T>::push_back(T&& t)
{
	if (space == last) {
		reserve(capacity() == 0 ? 8 : 2 * capacity());
	}
	// std::move is used to convert t into an rvalue, enabling the move constructor.
	new (space) T(std::move(t));
	++space;
}

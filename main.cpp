#include <iostream>
#include "Vector.h"

using namespace std;


int main() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	std::cout << v[1] << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.at(3) << std::endl;
}

#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector v1 = { 1.23, 3.45, 6.7, 8 };    
	for (int i = 0; i < v1.size(); ++i) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
}

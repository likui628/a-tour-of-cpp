#include <iostream>
#include "Vector.h"

using namespace std;

double read_and_sum(int s) {
	Vector v(s);
	for (int i = 0; i < s; ++i) {
		cin >> v[i];
	}

	double sum = 0;
	for (int i = 0; i < s; ++i) {
		sum += v[i];
	}
	return sum;
}

enum TrafficLight {
	green, yellow, red
};

TrafficLight& operator++(TrafficLight& t) {
	switch (t)
	{
	case red:
		t = green;
		break;
	case green:
		t = yellow;
		break;
	case yellow:
		t = red;
		break;
	}
	return t;
}

int main() {
	//double sum = read_and_sum(10);
	//cout << sum;

	TrafficLight light = TrafficLight::red;
	std::cout << light << std::endl;
	++light;
	std::cout << light << std::endl;
	++light;
	std::cout << light << std::endl;
	++light;
	std::cout << light << std::endl;
}

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


int main() {
	double sum=read_and_sum(10);
	cout << sum;
}

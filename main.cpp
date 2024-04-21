#include <iostream>

using namespace std;

struct Vector {
	double* elm;
	int sz;
};

void vector_init(Vector& v,int s) {
	v.elm = new double[s];
	v.sz = s;
}

double read_and_sum(int s) {
	Vector v;
	vector_init(v, s);
	for (int i = 0; i < s; ++i) {
		cin >> v.elm[i];
	}

	double sum = 0;
	for (int i = 0; i < s; ++i) {
		sum += v.elm[i];
	}
	return sum;
}


int main() {
	double sum=read_and_sum(10);
	cout << sum;
}

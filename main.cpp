#include <iostream>

using namespace std;

enum class Type {
	ptr, num
};

struct Node
{
	int data;
	Node* next;
};

struct Entity {
	string name;
	Type t;
	Value v;
};

union Value
{
	Node* p;
	int i;
};


void PrintEntity(const Entity& e) {
	if (e.t == Type::num) {
		cout << e.v.i << std::endl;
	}
	else {
		std::cout << e.v.p->data << std::endl;
	}
}

int main() {
	Entity e_num{ "Sample Entity",Type::num };
	e_num.v.i = 32;
	PrintEntity(e_num);

	Node* node = new Node{ 123, nullptr };
	Entity e_ptr{ "Node Entity", Type::ptr };
	e_ptr.v.p = node;
	PrintEntity(e_ptr);
}

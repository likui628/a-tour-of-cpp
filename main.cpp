#include <iostream>
#include <variant>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Entity {
	string name;
	variant<int, Node*> v;
};

void PrintEntity(const Entity& e) {
	if (holds_alternative<int>(e.v)) {
		cout << get<int>(e.v) << std::endl;
	}
	else {
		std::cout << get<Node*>(e.v)->data << std::endl;
	}
}

// the return type is "double"
auto mul(int i, double d) -> double {
	return i * d;
}

int main() {
	Entity e_num{ "Sample Entity",32 };
	PrintEntity(e_num);

	Node* node = new Node{ 123, nullptr };
	Entity e_ptr{ "Node Entity", node };
	PrintEntity(e_ptr);

	delete node;

	auto mulRes=mul(3, 7);
	std::cout << mulRes << std::endl;
}

#include <iostream>
#include <variant>

using namespace std;

struct Entity {
	string name;
	int value;
};

Entity read_entity(istream& is) {
	string name;
	int value;
	is >> name >> value;
	return { name,value };
}


int main() {
	auto [name, value] = read_entity(std::cin);
	std::cout << name << " " << value << std::endl;
}

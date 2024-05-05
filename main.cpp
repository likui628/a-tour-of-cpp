#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct Record {
	string name;
	int product_code;
};

struct RecordHash {
	size_t operator()(const Record& r)const {
		size_t h1 = hash<string>()(r.name);
		size_t h2 = hash<int>()(r.product_code);
		return h1 ^ (h2 << 1); // Shift h2 to avoid collision when h1 is similar
	}
};

struct RecordEqual {
	bool operator()(const Record& a, const Record& b) const {
		return a.name == b.name && a.product_code == b.product_code;
	}
};

ostream& operator<<(ostream& os, const Record& r) {
	os << "{\n" << r.name << ",\n" << r.product_code << ",\n}" << std::endl;
	return os;
}

int main() {
	unordered_set<Record, RecordHash, RecordEqual> my_set;
	Record r1{ "record1",1 };
	Record r2{ "record2",2 };
	Record r3{ "record3",3 };
	Record r4{ "record4",4 };

	my_set.insert(r1);
	my_set.insert(r2);
	my_set.insert(r3);
	my_set.insert(r4);

	auto result_1 = my_set.find({ "record2",2 });
	if (result_1 != my_set.end()) {
		std::cout << *result_1 << std::endl;
	}
	else {
		std::cout << "Record not found." << std::endl;
	}


	auto result_2 = my_set.find({ "record1",2 });
	if (result_2 != my_set.end()) {
		std::cout << *result_2 << std::endl;
	}
	else {
		std::cout << "Record not found." << std::endl;
	}


}

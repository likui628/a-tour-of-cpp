#include <iostream>
#include <regex>
#include <vector>

using namespace std;

struct Entry {
	string name;
	int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
	return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e) {
	return is >> e.name >> e.number;
}

vector<int> read_ints(istream& is, const string& terminator)
{
	vector<int> res;
	for (int i; is >> i; )
		res.push_back(i);

	if (is.eof())                            // fine: end of file
		return res;
	if (is.fail()) {                         // we failed to read an int; was it the terminator?
		is.clear();                          // reset the state to good()
		string s;
		if (is >> s && s == terminator)
			return res;
		is.setstate(ios_base::failbit);     // add fail() to is's state
	}
	return res;
}



int main() {
	Entry e1{ "entry",123 };
	std::cout << e1 << std::endl;

	Entry e2;
	std::cin >> e2;
	std::cout << e2 << std::endl;
}

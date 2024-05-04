#include <iostream>
#include <regex>
#include <vector>

using namespace std;

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
	auto v = read_ints(cin, "stop");
}

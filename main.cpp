#include <iostream>
#include "Vector.h"

using namespace std;
using namespace std::literals::string_literals;

int main() {
	string name = "Niels Stroustrup";


	string s = name.substr(6, 10);            // s = "Stroustrup"
	name.replace(0, 5, "nicholas1sss");          // name becomes "nicholas Stroustrup"
	name[0] = toupper(name[0]);            // name becomes "Nicholas Stroustrup"
	std::cout << name << std::endl;

	auto cat = "Cat"s;

	std::u8string utf = u8"ÄãºÃÖÐÎÄ£¡";
	std::cout << reinterpret_cast<const char*>(utf.c_str()) << std::endl;
}

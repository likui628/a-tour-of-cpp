#include <iostream>
#include <regex>

using namespace std;

int main() {
	std::string text = "Roses are #ff0000, violets are #0000ff all of my base are belong to you";

	std::string t = text;
	std::regex r{ R"(#([a-fA-F0-9]{6}|[a-fA-F0-9]{3}))" };

	for (std::smatch sm; std::regex_search(t, sm, r);) {
		std::cout << sm.str() << std::endl;	
		t = sm.suffix();
	}

	std::cout << text << std::endl;
}

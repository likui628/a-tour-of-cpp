#include <iostream>
#include "Vector.h"

using namespace std;
using namespace std::literals::string_view_literals;

string cat(string_view sv1, string_view sv2)
{
	string res{ sv1 };           // initialize from sv1
	return res += sv2;           // append from sv2 and return

}

void print_lower(string_view sv) {
	for (char c : sv) {
		std::cout << (char)tolower(c) << std::endl;
	}
}

string_view bad()
{
	string s = "Once upon a time";
	return { &s[5],4 };                // bad: returning a pointer to a local
}

int main() {
	string king = "Harold";
	auto s1 = cat(king, "William");                              // HaroldWilliam: string and const char*
	auto s2 = cat(king, king);                                   // HaroldHarold: string and string
	auto s3 = cat("Edward", "Stephen"sv);                        // EdwardStephen: const char * and string_view
	auto s4 = cat("Canute"sv, king);                             // CanuteHarold
	auto s5 = cat({ &king[0],2 }, "Henry"sv);                    // HaHenry
	auto s6 = cat({ &king[0],2 }, { &king[2],4 });               // Harold
	std::cout << s1 << "\n" << s2 << "\n" << s3 << "\n" << s4 << "\n" << s5 << "\n" << s6 << std::endl;

	print_lower(king);

	auto b = bad();
	// The behavior of out-of-range access to a string_view is undefined. 
	std::cout << b << std::endl;
}

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
	fs::path dir = fs::current_path() / "example_dir";

	// Create a directory
	if (!fs::exists(dir)) {
		fs::create_directory(dir);
		std::cout << "Directory created: " << dir << std::endl;
	}

	// Path to a file inside the directory
	fs::path file_path = dir / "example_file.txt";

	// Write to a file
	std::ofstream file_write(file_path);
	if (file_write.is_open()) {
		file_write << "Hello, Filesystem!";
		file_write.close();
		std::cout << "File written: " << file_path << std::endl;
	}
	else {
		std::cerr << "Unable to open file for writing: " << file_path << std::endl;
		return 1;
	}

	std::ifstream file_read(file_path);
	if (file_read.is_open()) {
		std::string line;
		while (std::getline(file_read, line)) {
			std::cout << "File read: " << line << std::endl;
		}
		file_read.close();
	}
	else {
		std::cerr << "Unable to open file for reading: " << file_path << std::endl;
		return 1;
	}

	std::cout << "list directory entry: " << std::endl;
	// directory_iterator can be iterated using a range-for loop
	for (auto const& dir_entry : std::filesystem::directory_iterator{ dir })
		std::cout << dir_entry.path() << '\n';
}

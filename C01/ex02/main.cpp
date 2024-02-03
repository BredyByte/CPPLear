#include <iostream>

int main() {
	const std::string s = "HI THIS IS BRAIN";
	const std::string* stringPTR = &s;
	const std::string& stringREF = s;


	std::cout << s << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	std::cout << &s << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	return (0);
}

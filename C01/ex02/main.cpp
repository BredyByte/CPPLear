#include <iostream>

int main() {
	std::string some = "HI THIS IS BRAIN";
	std::string *stringPTR = &some;
	std::string &stringREF = some;
	
	std::cout << &some << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << some << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}

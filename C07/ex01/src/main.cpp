#include "iter.hpp"

void someFunction(int &i) {
	std::cout << i << std::endl;
}

void someFunction(std::string &i) {
	std::cout << i << std::endl;
}

int main() {
	int arrInt[] = {1, 2, 3, 4, 5};
	std::string arrStr[] = {"one", "two", "three", "four", "five"};

	::iter(arrInt, 5, someFunction);
	::iter(arrStr, 5, someFunction);
	return 0;
}

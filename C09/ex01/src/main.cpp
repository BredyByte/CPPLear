#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Bad arguments, < ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\">" << std::endl;
		return -1;
	}
	try {
		RPN A(argv[1]);
		A.initCalc();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

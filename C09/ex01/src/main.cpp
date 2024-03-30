#include "RPN.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2) {
			throw std::runtime_error("Error: Bad arguments, < ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\">");
		}
		RPN A(argv[1]);
		A.initCalc();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}

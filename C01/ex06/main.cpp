#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}

	Harl harl;
	const std::string level = argv[1];

	harl.complain(level);

	return (0);
}

#include "PmergeMe.hpp"

std::string const VECTORFLAG = "VECTOR";
std::string const LISTFLAG = "LIST";

unsigned long long getTime() {
    return static_cast<unsigned long long>(clock());
}

std::string getBefore(char** argv, int size) {
	char ** charArray = argv;
	charArray++;
    std::string result;
    for (int i = 0; i < size; ++i) {
        result += charArray[i];
        if (i != size - 1) {
            result += " ";
		}
    }
    return result;
}

int main(int argc, char **argv) {
	try {
		if (argc < 2) {
			throw std::runtime_error("Error: Bad arguments, < ./PmergeMe 2 3 4 1 0 12 43 98> or ./PmergeMe `shuf -i 1-100000 -n 3000 | tr '\\n' ' '`");
		}
		PmergeMe A(argv, (argc - 1), VECTORFLAG);
		unsigned long long startTime= getTime();
		A.sortVect();
		unsigned long long endTime = getTime();
		unsigned long long durationA = endTime - startTime;

		PmergeMe B(argv, (argc - 1), LISTFLAG);
		startTime= getTime();
		B.sortList();
		endTime = getTime();
		unsigned long long durationB = endTime - startTime;

		std::string before = getBefore(argv, argc - 1);

		std::cout << "Before: " << before << std::endl;

		std::cout << "After: " << A << std::endl;
		std::cout << "After: " << B << std::endl;

		std::cout << "Time to process a range of " << (argc-1) << " elements with vector: " << durationA << " milliseconds" << std::endl;

		std::cout << "Time to process a range of " << (argc-1) << " elements with list: " << durationB << " milliseconds" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	return 0;
}

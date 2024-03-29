#include "BitcoinExchange.hpp"

bool checkDate(const std::string& date) {
    if (date.length() != 10) {
        return false;
	}

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
			if (date[i] != '-') {
            	return false;
			}
        }
		else {
            if (!isdigit(date[i])) {
                return false;
			}
        }
    }

    return true;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error (bad arguments): Usage:  <./btc ./file_route>";
	}
	try {
		BitcoinExchange A("data.csv");

		std::fstream my_file;
		my_file.open(argv[1], std::fstream::in);
		if (!my_file) {
			throw std::ios_base::failure("Can't open the file");
		}

		std::string line;
		while (std::getline(my_file, line)) {
			size_t pos = line.find("|");

			if (pos != std::string::npos) {
				std::istringstream ss(line);
				std::string date;
				std::string separator;
				float number;

				ss >> date;
				ss >> separator;
				ss >> number;
				if (!checkDate(date)) {
					std::cout << "Error: invalid date " << std::endl;
					continue;
				}
				else {
					std:: cout << date << " -> ";
				}
				if (number <= 0 || number >= 1000) {
					std::cout << "Error: invalid value" << std::endl;
					continue;
				}
				else {
					std::cout << number << " = " << A.getClosestRate(date) * number << std::endl;
				}
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}

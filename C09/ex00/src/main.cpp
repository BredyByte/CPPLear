#include "BitcoinExchange.hpp"

bool checkDate(const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    for (size_t i = 0; i < date.length(); ++i) {
        char c = date[i];
        if (!std::isdigit(c) && c != '-') {
            return false;
        }
    }


    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    if (month < 1 || month > 12) {
        return false;
    }

    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    }
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            maxDay = 29;
        }
		else {
            maxDay = 28;
        }
    }
    if (day < 1 || day > maxDay) {
        return false;
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
					std::cout << "Error: invalid date -> " <<  date <<  std::endl;
					continue;
				}
				else {
					std:: cout << date << " -> ";
				}
				if (number <= 0 || number >= 1000) {
					std::cout << "Error: invalid value -> " << number << std::endl;
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

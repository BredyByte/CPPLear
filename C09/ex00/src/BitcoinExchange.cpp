#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string const& filename) {
	std::fstream my_file;
	my_file.open(filename.c_str(), std::fstream::in);
	if (!my_file) {
		throw std::ios_base::failure("Can't open the file");
	}
	std::string line;
	while (std::getline(my_file, line)) {
		size_t pos = line.find(",");
		if (pos != std::string::npos) {
			std::string first = line.substr(0, pos);
			std::string second = line.substr(pos + 1);
			float number;
			std::istringstream ss(second);
			ss >> number;
			_csvData.insert(std::pair<std::string, float>(first, number));
		}
	}
};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) {
	this->_csvData = other._csvData;
};

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
	if (this != &other) {
		this->_csvData = other._csvData;
	}
	return *this;
};

float BitcoinExchange::getClosestRate(std::string date) {
	float tempValue = 0;
	std::map<std::string, float>::const_iterator it;
	for (it = _csvData.begin(); it != _csvData.end(); it++) {
		if (it->first <= date) {
			tempValue = it->second;
		}
	}
	return tempValue;
}

void BitcoinExchange::printCsvData() {
	std::map<std::string, float>::const_iterator it;
	for (it = _csvData.begin(); it != _csvData.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

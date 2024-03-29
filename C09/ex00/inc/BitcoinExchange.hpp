#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>

class BitcoinExchange {
private:
	BitcoinExchange();
	std::map<std::string, float> _csvData;

public:
	BitcoinExchange(std::string const& filename);
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& other);
	BitcoinExchange& operator=(BitcoinExchange const& other);
	void printCsvData();
	float getClosestRate(std::string date);
};

#endif

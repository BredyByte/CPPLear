#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const  ScalarConverter& other);
public:
	static void convert(const std::string& str);
};

#endif

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cstring>
#include <cstdlib>

class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const  ScalarConverter& other);

	static void convert(const std::string& str);
};

#endif

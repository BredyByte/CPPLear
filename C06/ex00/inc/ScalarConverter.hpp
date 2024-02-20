#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

	template<typename T>
	static T convert(const std::string& str);
};

#endif

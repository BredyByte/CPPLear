#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cstring>

class ScalarConverter {
private:
	static void convertToChar(const std::string& str);
	static void convertToInt(const std::string& str);
	static void convertToFloat(const std::string& str);
	static void convertToDouble(const std::string& str);
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const  ScalarConverter& other);

    class NonDisplayableChar : public std::exception {
    public:
        const char* what() const throw() {
            return "Non displayable character";
        }
    };
	static const int typesSize;
	static const std::string typeNames[3];
	static void convert(const std::string& str);
};

#endif

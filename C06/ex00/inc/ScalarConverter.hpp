#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

class ScalarConverter {
private:
	static void convertToChar(const std::string& str);
	static void convertToInt(const std::string& str);
	static float convertToFloat(const std::string& str);
	static double convertToDouble(const std::string& str);
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

	static void convert(const std::string& str);
};

#endif

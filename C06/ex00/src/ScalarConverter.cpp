#include "ScalarConverter.hpp"

const std::string typeNames[] = {"nan", "+inf", "-inf", "inf", "nanf", "+inff", "-inff", "inff"};
const int typesSize = 8;

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void charPrinting(int toInt) {
	if (toInt >= 0 && toInt <= 127) {
		if (!std::isprint(toInt) || toInt == 127) {
			std::cout << "char: Non displayable character" << std::endl;
		}
		else {
			std::cout << "char: '" << static_cast<char>(toInt) << "'" << std::endl;
		}
	}
	else {
		std::cout << "char: Impossible convert to char" << std::endl;
	}
}

void otherPrinting (int toInt, float toFloat, double toDouble) {
	if (std::isinf(toDouble) || std::isnan(toDouble) || toDouble > std::numeric_limits<int>::max() || toDouble < std::numeric_limits<int>::min()) {
		std::cout << "int: Impossible convert to int" << std::endl;
	}else {
		std::cout << "int: " << toInt << std::endl;
	}
	std::cout << "float: " << toFloat << ((toFloat == toInt) ? ".0" : "") << "f" << std::endl;
	std::cout << "double: " << toDouble << ((toDouble == toInt) ? ".0" : "") << std::endl;
}

void convertToInt(const std::string& str) {
	char *end;
	int intC = std::strtol(str.c_str(), &end, 10);
	if (str != end && *end == '\0') {
		int floatC = static_cast<float>(intC);
		int doubleC = static_cast<double>(intC);

		charPrinting(intC);
		otherPrinting(intC, floatC, doubleC);
		std::exit(EXIT_SUCCESS);
	}
}

void convertToFloat(const std::string& str) {
	char *end;
	float floatC = std::strtof(str.c_str(), &end);
	if (end != str && *end == 'f') {
		if (*(end + 1) == '\0') {
			double doubleC = static_cast<double>(floatC);
			int intC = static_cast<int>(floatC);

			charPrinting(intC);
			otherPrinting(intC, floatC, doubleC);
			std::exit(EXIT_SUCCESS);
		}
	 }
}

void convertToDouble(const std::string& str) {
	char *end;
	double doubleC = std::strtod(str.c_str(), &end);
	if (end != str && doubleC != static_cast<int>(doubleC) && *end == '\0') {
		int intC = static_cast<int>(doubleC);
		float floatC = static_cast<float>(doubleC);

		charPrinting(intC);
		otherPrinting(intC, floatC, doubleC);
		std::exit(EXIT_SUCCESS);
    }
}

void ScalarConverter::convert(const std::string& str) {
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
		std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return;
	}
	for (int i = 0; i < typesSize; i++) {
		if (str == typeNames[i]){
			std::cout << "char: Invalid conversion to char" << std::endl;
			std::cout << "int: Invalid conversion to int" << std::endl;
			std::cout << "float: " << typeNames[i%4] << "f" << std::endl;
			std::cout << "double: " << typeNames[i%4] << std::endl;
			return ;
		}
	}
	convertToFloat(str);
	convertToDouble(str);
	convertToInt(str);
	
	std::cerr << "Error: bad argument" << std::endl;
}

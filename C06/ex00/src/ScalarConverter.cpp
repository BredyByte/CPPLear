#include "ScalarConverter.hpp"

const std::string ScalarConverter::typeNames[] = {"nan", "+inf", "-inf"};
const int ScalarConverter::typesSize = 3;

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void ScalarConverter::convertToChar(const std::string& str) {
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
		std::cout << "char: '" << str[0] << "'" << std::endl;
		return ;
	}
	int res = std::atoi(str.c_str());
	if (res >= 0 && res <= 127) {
		if (!std::isprint(res) || res == 32 || res == 127) {
			std::cout << "Non displayable character" << std::endl;
			return ;
		}
		std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::convertToInt(const std::string& str) {
	int mediores = std::atoi(str.c_str());
	float result = 0;

	std::stringstream s(str);
	s >> result;
	if (mediores == 0) {
		if (s.fail() || !s.eof()) {
			std::cout << "Invalid conversion to int" << std::endl;
			return ;
		}
	}
	std::cout << "int: " << mediores << std::endl;
}


void ScalarConverter::convertToFloat(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "+inf" || str == "-inf" || str == "-inff") {
		std::cout << "float: " << str << "f" << std::endl;
		return ;
	}
	if (str == "nanf" || str == "+inff" || str == "+inff" || str == "-inff" || str == "-inff") {
		std::cout << "float: " << str << std::endl;
		return ;
	}
	if (str.size() == 1 && std::isdigit(str[0])) {
		std::cout << "float: " << str << ".0f" << std::endl;
		return ;
	}
	std::istringstream iss(str);
	int value;
	if (iss >> value) {
		std::cout << "float: " << value << ((str.find('.') != std::string::npos) ? "f" : ".0f") << std::endl;
		return ;
	}
	std::cout << "Invalid conversion to float" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& str) {
	std::istringstream iss(str);
	double value;
	if (iss >> value) {
		std::cout << "double: " << value << std::endl;
		return ;
	}
	std::cout << "Invalid conversion to double" << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}

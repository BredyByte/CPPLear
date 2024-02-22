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
	for (int i = 0; i < typesSize; i++) {
		if (str == typeNames[i]){
			std::cout << "float: " << (str+"f") << std::endl;
			return ;
		}
		else if (str == typeNames[i] + "f") {
			std::cout << "float: " << str << std::endl;
			return ;
		}
	}

	if (str.size() == 1 && std::isdigit(str[0])) {
		std::cout << "float: " << str << ".0f" << std::endl;
		return ;
	}

	std::istringstream iss(str);
	float value;
	if (iss >> value) {
		std::cout << "float: " << value << ((value == static_cast<int>(value)) ? ".0f" : "f") << std::endl;
		return ;
	}
	std::cout << "Invalid conversion to float" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& str) {
	for (int i = 0; i < typesSize; i++) {
		if (str == typeNames[i]){
			std::cout << "double: " << str << std::endl;
			return ;
		}
	}

	if (str.size() == 1 && std::isdigit(str[0])) {
		std::cout << "double: " << str << ".0" << std::endl;
		return ;
	}

	std::istringstream iss(str);
	double value;
	if (iss >> value) {
		std::cout << "double: " << value << ((value == static_cast<int>(value)) ? ".0" : "") << std::endl;
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

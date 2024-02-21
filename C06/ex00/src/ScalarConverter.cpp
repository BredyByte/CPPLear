#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

int retInt(const std::string& str) {
	std::stringstream s(str);
	int res;

	s >> res;

	if (s.fail() || !s.eof() || res < 0 || res > 127) {
		return -1;
	}
	return res;
}

void ScalarConverter::convertToChar(const std::string& str) {
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
		std::cout << "char: " << str[0] << std::endl;
		return ;
	}

	try {
		int res = std::stoi(str);
		if (res >= 0 && res <= 127) {
			if (!std::isprint(res) || res == 32 || res == 127) {
				throw NonDisplayableChar();
			}
			std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
			return ;
		}
		else {
			throw std::invalid_argument("Invalid conversion to char");
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid conversion to char" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Invalid conversion to char" << std::endl;
	}
	catch (const ScalarConverter::NonDisplayableChar& e) {
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void ScalarConverter::convertToInt(const std::string& str) {
	std::stringstream s(str);
	int result;

	s >> result;

    if (s.fail() || !s.eof()) {
		throw std::invalid_argument("Invalid conversion to int");
	}

	char c;
    if (s.get(c) && !std::isspace(c)) {
        throw std::invalid_argument("Invalid conversion to int");
    }

	std::cout << "int: " << result << std::endl;
}

float ScalarConverter::convertToFloat(const std::string& str) {
	std::istringstream iss(str);
	float value;
	if (iss >> value) {
		return value;
	}
	throw std::invalid_argument("Invalid conversion to float");
}

double ScalarConverter::convertToDouble(const std::string& str) {
	std::istringstream iss(str);
	double value;
	if (iss >> value) {
		return value;
	}
	throw std::invalid_argument("Invalid conversion to double");
}


void ScalarConverter::convert(const std::string& str) {
	try {
		convertToChar(str);
	}
	catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

	try {
		convertToInt(str);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		float f = convertToFloat(str);
		std::cout << "float: " << f << ".0f" <<std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		double d = convertToDouble(str);
		std::cout << "float: " << d << ".0" <<std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
}

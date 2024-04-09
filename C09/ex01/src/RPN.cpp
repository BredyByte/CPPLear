#include "RPN.hpp"

const char* signs[] = {"-", "+", "*", "/"};
const int signsSize = 4;

RPN::RPN() {};

RPN::~RPN() {};

RPN::RPN(RPN const& other) {
	*this = other;
};

RPN& RPN::operator=(RPN const& other) {
	if (this != &other) {
		_numbers = other._numbers;
	}
	return *this;
}

std::string getSign(std::string const& chunk) {
	int i = 0;
	while (i < signsSize) {
		if (chunk.find(signs[i]) != std::string::npos) {
			return signs[i];
		}
		++i;
	}
	return "";
}

RPN::RPN(std::string const& str) {
	std::istringstream ss(str);
	std::string part;
	_res = 0;

	while (ss >> part) {
		if (part.size() == 1) {
			std::string sign = getSign(part);
			if (isdigit(part[0])) {
				char* c;
				float num = std::strtof(part.c_str(), &c);
				_numbers.push(num);
			}
			else if (_numbers.size() < 2 || sign  == "") {
				throw std::runtime_error("Error: Can't parse it, bad argumens.");
			}
			else if (sign != "") {
				float num1 = _numbers.top();
				_numbers.pop();
				float num2 = _numbers.top();
				_numbers.pop();
				if (sign == "+") {
					_numbers.push(num2 + num1);
				}
				else if (sign == "-") {
					_numbers.push(num2 - num1);
				}
				else if (sign == "*") {
					_numbers.push(num2 * num1);
				}
				else if (sign == "/") {
					if (num1 == 0) {
						throw std::runtime_error("Error: Can't divide by zero.");
					}
					_numbers.push(num2 / num1);
				}
			}
			_res = _numbers.top();
		}
		else {
			throw std::runtime_error("Error: Can't parse it, bad argumens chunk more than 1 char.");
		}
	}
	if (_numbers.size() != 1) {
		throw std::runtime_error("Error: Can't parse it, bad argumens.");
	}
	std::cout << "Result: " << _res << std::endl;
};

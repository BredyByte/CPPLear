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
		_signs = other._signs;
	}
	return *this;
}

void RPN::initCalc() {
	if (_numbers.empty() || (_numbers.size() - 1 != _signs.size())) {
		throw std::invalid_argument("Error: Can't calculate it, bad argumens");
	}

	int _res = _numbers.front();
	_numbers.pop();

    while (!_numbers.empty() && !_signs.empty()) {
        int num = _numbers.front();
        _numbers.pop();
        std::string sign = _signs.front();
        _signs.pop();

        if (sign == "+") {
            _res += num;;
        }
		else if (sign == "-") {
            _res -= num;;
        }
		else if (sign == "*") {
            _res *= num;;
        }
		else if (sign == "/") {
            _res /= num;
        }
    }

    std::cout << "Result: " << _res << std::endl;
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
			std::string sign;
			if (isdigit(part[0])) {
				int num = std::atoi(part.c_str());
				_numbers.push(num);
			}
			else if ((sign = getSign(part)) != "") {
				_signs.push (sign);
			}
			else {
				throw std::runtime_error("Error: Can't parse it, bad argumens");
			}
		}
	}
};

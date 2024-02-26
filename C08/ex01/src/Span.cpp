#include "Span.hpp"

Span::Span() : _size(0) {};

Span::Span(unsigned int N) : _size(N) {}

Span::Span(Span& other) : _size(other.getSize()), _arr(other.getVector()) {}

Span::~Span() {};

Span& Span::operator=(Span& other) {
	if (this != &other) {
		_size = other.getSize();
		_arr = other.getVector();
	}
	return *this;
}

void runTimeCustomException(std::string str) {
	std::stringstream ss;
	ss << str;
	throw std::runtime_error(ss.str());
}

void Span::addNumber(int number) {
	try {
		if (_arr.size() < _size) {
			_arr.push_back(number);
		}
		else {
			runTimeCustomException("Error: Stack Overflow");
		}
	}
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int Span::shortestSpan() {
	try {
		if (_arr.size() <= 1) {
			runTimeCustomException("Error: Not enough numbers stored.");
		}
		else {
			std::vector<int> copy = _arr;
			std::sort(copy.begin(), copy.end());
			int minS = copy[1] - copy[0];
			for(size_t i = 2; i < copy.size(); i++) {
				minS = std::min(minS, copy[i] - copy[i - 1]);
			}
			return minS;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return -1;
}

int Span::longestSpan() {
	try {
		if (_arr.size() <= 1) {
			runTimeCustomException("Error: Not enough numbers stored.");
		}
		else {
			std::vector<int> copy = _arr;
			std::sort(copy.begin(), copy.end());
			return copy.back() - copy.front();
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return -1;
}

void Span::fillRange(Iterator beg, Iterator end) {
	_arr.clear();
	for (Iterator it = beg; it != end; ++it) {
		if (_arr.size() >= _size) {
			break;
		}
		this->addNumber(*it);
	}
}

unsigned int Span::getSize() {
	return _size;
}

std::vector<int> Span::getVector() {
	return _arr;
}

#include "Span.hpp"

Span::Span() : _size(0) {};

Span::Span(unsigned int N) : _size(N) {}

Span::Span(Span const& other) : _size(other.getSize()), _arr(other.getVector()) {}

Span::~Span() {};

Span& Span::operator=(Span const& other) {
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
	if (_arr.size() < _size) {
		_arr.push_back(number);
	}
	else {
		throw std::runtime_error("Error: Stack Overflow.");
	}
}

int Span::shortestSpan() {
	if (_arr.size() <= 1) {
		throw std::runtime_error("Error: Not enough numbers stored.");
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
	return -1;
}

int Span::longestSpan() {
	if (_arr.size() <= 1) {
		throw std::runtime_error("Error: Not enough numbers stored.");
	}
	else {
		std::vector<int> copy = _arr;
		std::sort(copy.begin(), copy.end());
		return copy.back() - copy.front();
	}
	return -1;
}

void Span::fillRange(Iterator beg, Iterator end) {
	_arr.clear();
	for (Iterator it = beg; it != end; ++it) {
		this->addNumber(*it);
	}
}

unsigned int Span::getSize() const {
	return _size;
}

std::vector<int> Span::getVector() const {
	return _arr;
}

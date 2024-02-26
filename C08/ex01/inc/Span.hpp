#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

class Span {
	private:
		unsigned int _size;
		std::vector<int> _arr;

	public:
		typedef std::vector<int>::iterator Iterator;
		Span();
		Span(unsigned int N);
		~Span();
		Span(Span& other);
		Span& operator=(Span& other);

		unsigned int getSize();
		std::vector<int> getVector();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillRange(Iterator beg, Iterator end);

};

#endif

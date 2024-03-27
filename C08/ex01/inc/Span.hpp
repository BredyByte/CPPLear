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
		Span(Span const& other);
		Span& operator=(Span const& other);

		unsigned int getSize() const;
		std::vector<int> getVector() const;

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillRange(Iterator beg, Iterator end);

};

#endif

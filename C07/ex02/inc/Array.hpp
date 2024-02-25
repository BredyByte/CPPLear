#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

template <class T>
class Array {
	private:
		T *m_array;
		unsigned int m_nSize;

	public:
		Array();
		Array(unsigned int nSize);
		Array(const Array& other);
		Array& operator=(const Array& other);
		virtual ~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		int	size();
};

#include "../src/Array.tpp"

#endif

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>


template <class myType>
void iter(myType *arrDir, size_t arrLen, void (*f)(myType &)) {
	for (size_t i = 0; i < arrLen; i++) {
		f(arrDir[i]);
	}
}

#endif

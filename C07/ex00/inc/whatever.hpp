#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <string>

template <class myType>
void swap(myType &a, myType &b) {
	myType tmp = a;
	a = b;
	b = tmp;
}

template <class myType>
myType min(myType a, myType b) {
	return (a < b) ? a : b;
}

template <class myType>
myType max(myType a, myType b) {
	return (a > b) ? a : b;
}

#endif

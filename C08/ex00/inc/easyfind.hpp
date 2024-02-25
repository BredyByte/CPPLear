#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

template <class T>
void easyfind(T &container, int value) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << "Checking value " << *it << std::endl;
		if (*it == value) {
			std::cout << "Value " << value << " found in container" << std::endl;
			return;
		}
	}
	std::stringstream ss;
	ss << "Error: value " << value << " not found in container";
	throw std::runtime_error(ss.str());
}

#endif

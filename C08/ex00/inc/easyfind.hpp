#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

template <class T>
void easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        std::cout << "Value " << value << " found in container" << std::endl;
    } else {
        std::stringstream ss;
        ss << "Error: value " << value << " not found in container";
        throw std::runtime_error(ss.str());
    }
}

#endif

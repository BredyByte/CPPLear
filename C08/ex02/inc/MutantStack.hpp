#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>

template <class T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>() {}
	~MutantStack() {};
	MutantStack(MutantStack const& other) : std::stack<T>(other) {};
	MutantStack& operator=(MutantStack const& other) {
		if (this == &other) {
			return *this;
		}

		std::stack<T>::operator=(other);
		return *this;
	}

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	void clear() {
		while (!std::stack<T>::empty()) {
			std::stack<T>::pop();
		}
	}
};

#endif

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
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			std::stack<T>::operator=(other);
			return *this;
		}

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}
};

#endif

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <stack>

template <class T>
class MutantStack {
	private:
		std::vector<T> _arr;

	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack& other);
		MutantStack& operator=(MutantStack& other);
		std::vector<T> getVector();

		bool empty() const;
		size_t size() const;
		T& top();
		void push(const T&);
		void pop();
		void swap(MutantStack& other);

};

#include "../src/MutantStack.tpp"

#endif

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(MutantStack& other) : _arr(other.getVector()) {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
std::vector<T> MutantStack<T>::getVector() {
    return _arr;
}

void runTimeCustomException(std::string str) {
	std::stringstream ss;
	ss << str;
	throw std::runtime_error(ss.str());
}

template <class T>
bool MutantStack<T>::empty() const {
    return _arr.empty();
}

template <class T>
size_t MutantStack<T>::size() const {
    return _arr.size();
}

template <class T>
T& MutantStack<T>::top() {
    try {
        if (_arr.empty()) {
            runTimeCustomException("Stack is empty. Cannot retrieve top element.");
        }
        else {
            return _arr.back();
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return _arr.back();
}

template <class T>
void MutantStack<T>::push(const T& elem) {
    _arr.push_back(elem);
}

template <class T>
void MutantStack<T>::pop() {
    try {
        if (_arr.empty()) {
            runTimeCustomException("Stack is empty. Cannot retrieve top element.");
        }
        else {
            _arr.pop_back();
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

template <class T>
void MutantStack<T>::swap(MutantStack& other) {
    std::vector<T> copy = this.getVector();
    
}

template <class T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack& other) {
    if (this != &other) {
        _arr = other.getVector();
    }
    return *this;
}

#endif




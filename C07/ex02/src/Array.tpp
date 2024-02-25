#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array() : m_array(NULL), m_nSize(0) {};

template <class T>
Array<T>::Array(unsigned int nSize) {
    if (nSize > 0) {
        m_nSize = nSize;
        m_array = new T[nSize];
    } else {
        m_nSize = 0;
        m_array = NULL;
    }
};

template <class T>
Array<T>::Array(const Array& other) {
    if (this != &other) {
        m_nSize = other.m_nSize;
        m_array = new T[m_nSize];
        for (unsigned int i = 0; i < m_nSize; i++) {
            m_array[i] = other.m_array[i];
        }
    }
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        m_nSize = other.m_nSize;
        if (m_array != NULL) {
            delete[] m_array;
        }
        m_array = new T[m_nSize];
        for (unsigned int i = 0; i < m_nSize; i++) {
            m_array[i] = other.m_array[i];
        }
    }
    return *this;
}

template <class T>
Array<T>::~Array() {
	delete[] m_array;
}

template <class T>
int Array<T>::size() {
    return m_nSize;
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
    if (index < m_nSize) {
        return m_array[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index < m_nSize) {
        return m_array[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

#endif




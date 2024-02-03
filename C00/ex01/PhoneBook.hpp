#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"
#include "Contact.hpp"


class PhoneBook {
public:
	// Constructor
	PhoneBook();

	// Destructor
	~PhoneBook();

	// Member functions
	void Search();
	void Add();

private:
	static const int _maxSize = 8;
	Contact			_contacts[_maxSize];
	int				_currentSize;

};

#endif

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
public:

	// Constructor
	PhoneBook();

	// Destructor
	~PhoneBook();

	// Member functions
	void Search(std::string name);
	void Add();
	void PrintPhoneBook();

private:

	static const int _maxSize = 8;
	Contact			_contacts[_maxSize];
	int				_currentSize;

};

#endif

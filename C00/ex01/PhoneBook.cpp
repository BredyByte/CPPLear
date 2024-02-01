#include "main.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	_currentSize = 0;
}

PhoneBook::~PhoneBook() {

}

static std::string FormatString(const std::string& str) {
	if (str.length() >= 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

void PhoneBook::Search() {
    if (_currentSize == 0) {
        std::cout << "PhoneBook is empty :(" << std::endl;
        return;
    }

	std::cout << std::setfill('_') << std::setw(42) << "_" << std::setfill(' ') << std::endl;
    std::cout << "| Index |";
    std::cout << std::setw(10) << "First Name|";
    std::cout << std::setw(10) << "Last  Name|";
    std::cout << std::setw(10) << "Nick  Name|" << std::endl;
	std::cout << std::setfill('_') << std::setw(42) << "_" << std::setfill(' ') << std::endl;
    for (int i = 0; i < _currentSize; i++) {
        std::cout << "|   " << i + 1 << "   |";
        std::cout << std::setw(10) << FormatString(_contacts[i].GetFirst()) << "|";
        std::cout << std::setw(10) << FormatString(_contacts[i].GetLast()) << "|";
        std::cout << std::setw(10) << FormatString(_contacts[i].GetNick()) << "|" << std::endl;
		std::cout << std::setfill('_') << std::setw(42) << "_" << std::setfill(' ') << std::endl;
    }

	std::string index = GetData("Index[1-8]: ", 1);
	int i = (index[0] - '0') - 1;
	if (i < 0 || i >= _currentSize)
		std::cout << "Contact not found :(" << std::endl;
	else {
		std::cout << "First Name: " << _contacts[i].GetFirst() << std::endl;
		std::cout << "Last Name: " << _contacts[i].GetLast() << std::endl;
		std::cout << "Nick Name: " << _contacts[i].GetNick() << std::endl;
		std::cout << "Phone: " << _contacts[i].GetPhone() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[i].GetSecret() << std::endl;
	}
}

void PhoneBook::Add() {
	if (_currentSize == _maxSize) {
		for (int i = 0; i < _maxSize; i++) {
			if (i == _maxSize - 1) {
				_contacts[i].SetFirst(GetData("First Name: ", 0));
				_contacts[i].SetLast(GetData("Last Name: ", 0));
				_contacts[i].SetNick(GetData("Nick Name: ", 0));
				_contacts[i].SetPhone(GetData("Phone Number: ", 0));
				_contacts[i].SetSecret(GetData("Your Darkest Sicret: ", 0));
			}
			else {
				_contacts[i] = _contacts[i + 1];
			}
		}
		return;
	}
	_contacts[_currentSize].SetFirst(GetData("First Name: ", 0));
	_contacts[_currentSize].SetLast(GetData("Last Name: ", 0));
	_contacts[_currentSize].SetNick(GetData("Nick Name: ", 0));
	_contacts[_currentSize].SetPhone(GetData("Phone Number: ", 0));
	_contacts[_currentSize].SetSecret(GetData("Your Darkest Sicret: ", 0));
	_currentSize++;
}

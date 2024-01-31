#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_currentSize = 0;
	std::cout << "Init PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "Destroy PhoneBook" << std::endl;
}

void PhoneBook::Search(std::string name) {
	for (int i = 0; i < _maxSize; i++) {
		if (_contacts[i].GetFirst() == name) {
			std::cout << "Contact is find!" << std::endl;
		}
		else {
			std::cout << "Contact doesn't find :(" << std::endl;
		}
	}
}

void PhoneBook::Add() {
	if (_currentSize >= _maxSize) {
		std::cout << "PhoneBook is full" << std::endl;
	}
	else {
		_contacts[_currentSize].SetFirst("Davyd");
		_contacts[_currentSize].SetLast("Bredykh");
		_contacts[_currentSize].SetNick("FOll");
		_contacts[_currentSize].SetPhone("121-2-312-213");
		_contacts[_currentSize].SetPhone("popa");
		_currentSize++;
	}
}

void PhoneBook::PrintPhoneBook() {
	if (_currentSize == 0)
		std::cout << "PhoneBook is empty :";
	for (int i = 0; i < _currentSize; i++) {
		std::cout << _contacts[i].GetFirst() << std::endl;
		std::cout << _contacts[i].GetLast() << std::endl;
		std::cout << _contacts[i].GetNick() << std::endl;
		std::cout << _contacts[i].GetPhone() << std::endl;
		std::cout << _contacts[i].GetSecret() << std::endl;
	}
}


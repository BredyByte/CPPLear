#include "Dog.hpp"

Dog &Dog::operator=(const Dog& other) {
	this->_type = other._type;
	return *this;
}

Dog::Dog(): Animal() {
	_type = "Dog";
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::Dog(std::string type): Animal(type) {
	_type = "Dog";
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::Dog(Dog& other): Animal(other._type) {
	_type = other._type;
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "'🐶 Annoying Barking...'" << std::endl;
}

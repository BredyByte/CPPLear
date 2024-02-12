#include "Dog.hpp"

Dog &Dog::operator=(const Dog& other) {
	if (this != &other) {
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}

	return *this;
}

Dog::Dog(): Animal() {
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::Dog(std::string type): Animal(type) {
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::Dog(Dog& other): Animal(other._type) {
	_brain = new Brain(*other._brain);
	_type = other._type;
	std::cout << "Dog Constructor " << this->_type << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "'🐶 Annoying Barking...'" << std::endl;
}

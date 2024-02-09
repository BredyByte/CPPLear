#include "Cat.hpp"

Cat &Cat::operator=(const Cat& other) {
	this->_type = other._type;
	return *this;
}

Cat::Cat(): Animal() {
	_type = "Cat";
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::Cat(std::string type): Animal(type) {
	_type = "Cat";
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::Cat(Cat& other): Animal(other._type) {
	_type = other._type;
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "'🐱 Annoying Meowing...'" << std::endl;
}

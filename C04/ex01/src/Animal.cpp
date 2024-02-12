#include "Animal.hpp"

Animal &Animal::operator=(const Animal& other) {
	this->_type = other._type;
	return *this;
}

Animal::Animal(): _type("Untyped") {
	std::cout << "Animal Constructor " << this->_type << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal Constructor " << this->_type << std::endl;
}

Animal::Animal(Animal &other) {
	this->_type = other._type;
	std::cout << "Animal Constructor " << this->_type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "'🐚 Some rare sound'" << std::endl;
}

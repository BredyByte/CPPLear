#include "WrongAnimal.hpp"

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
	this->_type = other._type;
	return *this;
}

WrongAnimal::WrongAnimal(): _type("WrongUntyped") {
	std::cout << "WrongAnimal Constructor " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal Constructor " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other) {
	this->_type = other._type;
	std::cout << "WrongAnimal Constructor " << this->_type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "'👾 Some rare sound by Wrong Animal bicho'" << std::endl;
}

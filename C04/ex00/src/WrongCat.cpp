#include "WrongCat.hpp"

WrongCat &WrongCat::operator=(const WrongCat& other) {
	this->_type = other._type;
	return *this;
}

WrongCat::WrongCat(): WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat Constructor " << this->_type << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type) {
	_type = "WrongCat";
	std::cout << "WrongCat Constructor " << this->_type << std::endl;
}

WrongCat::WrongCat(WrongCat& other): WrongAnimal(other._type) {
	_type = other._type;
	std::cout << "WrongCat Constructor " << this->_type << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "'🐁 Annoying Meowing... by Wrong Cat bicho'" << std::endl;
}

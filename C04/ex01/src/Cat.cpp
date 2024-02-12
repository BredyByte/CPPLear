#include "Cat.hpp"

Cat &Cat::operator=(const Cat& other) {
    if (this != &other) {
        delete _brain;
        _brain = new Brain(*other._brain);
        _type = other._type;
    }
    return *this;
}

Cat::Cat(): Animal() {
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::Cat(std::string type): Animal(type) {
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::Cat(Cat& other): Animal(other._type) {
	_brain = new Brain(*other._brain);
	_type = other._type;
	std::cout << "Cat Constructor " << this->_type << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "'🐱 Annoying Meowing...'" << std::endl;
}

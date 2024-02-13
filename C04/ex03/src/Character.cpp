#include "Character.hpp"

Character::Character() : _name("Nameless") {

}

Character::Character(std::string name) : _name(name) {

}

Character::~Character() {

}

Character::Character(Character& other) {
	if (this != &other) {
		this->_name = other._name;
	}
}

Character& Character::operator=(Character& other) {
	if (this != &other) {
		this->_name = other._name;
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

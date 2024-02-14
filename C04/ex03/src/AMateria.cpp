#include "AMateria.hpp"

AMateria::AMateria() : _type("Default") {

}

AMateria::AMateria(std::string const& type) : _type (type) {

}

AMateria::AMateria(AMateria& other) : _type (other._type) {

}

AMateria::~AMateria() {

}

AMateria& AMateria::operator=(AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

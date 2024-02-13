#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

};

Cure::Cure(const Cure& other) : AMateria("cure") {
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}

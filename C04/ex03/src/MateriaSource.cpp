#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : _curr(0) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) : _curr(other._curr) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = other._materias[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other)	{
		for (int i = 0; i < 4; i++) {
			if (this->_materias[i] != NULL) {
				delete _materias[i];
			}
			this->_materias[i] = other._materias[i]->clone();
		}
		this->_curr = other._curr;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* mater) {
	if (_curr >= 4) {
		std::cout << "MateriaSource is full" << std::endl;
		delete mater;
		return;
	}

	this->_materias[_curr] = mater->clone();
	this->_curr++;
	delete mater;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_curr; i++) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}

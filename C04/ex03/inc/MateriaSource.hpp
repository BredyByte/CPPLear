#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria*	_materias[4];
	int			_curr;

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& other);

	void learnMateria(AMateria* mater);
	AMateria* createMateria(std::string const & type);
};

#endif

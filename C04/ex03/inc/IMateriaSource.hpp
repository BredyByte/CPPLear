#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include "AMateria.hpp"


class IMateriaSource {
public:
	IMateriaSource();
	IMateriaSource(IMateriaSource& other);
	IMateriaSource& operator=(IMateriaSource& other);
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

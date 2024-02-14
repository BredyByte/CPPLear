#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->unequip(0);
	ICharacter* bob = new Character("bob");
	me->equip(src->createMateria("cure"));
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete src;
	delete me;
	Character::resetWorldStack();
	return 0;
}

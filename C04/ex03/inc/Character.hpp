#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(std::string name);
	~Character();
	Character(Character& other);
	Character& operator=(Character& other);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	static void resetWorldStack();

private:
	static AMateria*	_worldStack[100];
	static int			_worldStackCurr;
	AMateria*			_inventory[4];
	int					_curr;
	std::string			_name;
};


#endif

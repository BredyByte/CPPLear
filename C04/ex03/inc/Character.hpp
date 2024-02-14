#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
	static const int	MAX_INVENTORY = 4;
	static const int	MAX_WORLD_OVERFLOW = 100;
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
	static AMateria* getWorldStack(int idx);

private:
	static AMateria*	_worldStack[MAX_WORLD_OVERFLOW];
	static int			_worldStackCurr;
	AMateria*			_inventory[MAX_INVENTORY];
	int					_curr;
	std::string			_name;
};


#endif

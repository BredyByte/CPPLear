#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"

/*
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
 */
class Character : public ICharacter {
public:
	Character();
	Character(std::string name);
	~Character();
	Character(Character& other);
	Character& operator=(Character& other);
	std::string const & getName() const;

private:
	std::string _name;
	


	static
};


#endif

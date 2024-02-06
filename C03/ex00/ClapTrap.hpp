#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
	// Constructors
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &obj);

	// Desctrustor
	~ClapTrap();

	// Member Functions
	/* Getters */
	std::string getName();
	int			getHealth();
	int			getEnergy();
	int			getDamage();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	int	_health ;
	int _energy;
	int	_damage;
};

#endif

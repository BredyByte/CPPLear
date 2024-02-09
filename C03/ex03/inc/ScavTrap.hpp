#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap  {
public:
	// Constructor
	ScavTrap();
	ScavTrap(std::string name);

	// Destructor
	~ScavTrap();

	// Member functions
	ScavTrap &operator=(const ScavTrap &other);
	void printMessage(std::string message, std::string flag, std::string target);
	virtual void guardGate();

private:

};

#endif

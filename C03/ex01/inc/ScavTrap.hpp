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
	void printMessage(std::string message, std::string flag, std::string target);
	ScavTrap &operator=(const ScavTrap &other);

	// Member functions
	void guardGate();

private:

};

#endif

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
	// Constructor
	FragTrap();
	FragTrap(std::string name);

	// Destructor
	~FragTrap();

	//Member Functions
	FragTrap &operator=(const FragTrap &other);
	void highFivesGuys();
	void printMessage(std::string message, std::string flag, std::string target);

	private:
};

#endif

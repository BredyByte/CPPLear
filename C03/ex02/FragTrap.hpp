#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	// Constructor
	FragTrap(std::string name);

	// Destructor
	~FragTrap();

	//Member Functions
	void highFivesGuys();

	private:
};

#endif

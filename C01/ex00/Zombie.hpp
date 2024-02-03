#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	// Constructor
	Zombie( std::string name );

	// Member function
	void announce();

	// Destructor
	~Zombie();

private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
#endif

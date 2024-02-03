#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	// Constructor
	Zombie();
	Zombie(std::string name);

	// Member function
	void announce();
	void SetName(std::string name);

	// Destructor
	~Zombie();

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

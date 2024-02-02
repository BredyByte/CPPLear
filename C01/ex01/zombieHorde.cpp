#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	if ( N <= 0 ) {
		return (NULL);
	}
	std::cout << "The zombie horde has risen up" << std::endl;
	Zombie *Zombies = new Zombie[N];
	for ( int i = 0; i < N; i++ ) {
		Zombies[i].SetName(name);
		Zombies[i].announce();
	}
	return (Zombies);
}

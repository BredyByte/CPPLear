#include "Zombie.hpp"

int main() {
	Zombie zombie = Zombie("NameLess");
	Zombie *Horde = zombieHorde(5, "Knight");
	delete[] Horde;
	return (0);
}

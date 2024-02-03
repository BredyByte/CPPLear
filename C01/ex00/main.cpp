#include "Zombie.hpp"

int main() {
	Zombie *zombie1 = newZombie("Foo");
	zombie1->announce();

	randomChump("Nameless");
	delete (zombie1);

	return (0);
}

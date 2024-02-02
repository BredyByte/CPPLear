#include "Zombie.hpp"

int main( void ) {
	Zombie *zombie1 = newZombie("Foo");
	zombie1->announce();

	randomChump("nameless");
	delete (zombie1);
	return (0);
}

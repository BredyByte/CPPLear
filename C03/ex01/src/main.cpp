#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap a("Pablo");
	ScavTrap g("LOL");
	ScavTrap b = a;

	a = g;
	a.attack(b.getName());
	b.attack(a.getName());
	a.beRepaired(10);
	a.takeDamage(100);
	a.takeDamage(10);
	b.takeDamage(100);
	b.guardGate();
	return 0;
}

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Davyd");
	ClapTrap b;

	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.takeDamage(9);
	b.beRepaired(10);
	a.attack(b.getName());
	b.beRepaired(10);
	return 0;
}

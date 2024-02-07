#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Davyd");
	ClapTrap b("Pablo");

	b = a;
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.attack(a.getName());
	b.beRepaired(10);
	b.beRepaired(10);
	return 0;
}

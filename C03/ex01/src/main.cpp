#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap a("Pablo");
	ScavTrap b("Davyd");

	a = b;
	a.attack(b.getName());
	a.beRepaired(10);
	a.takeDamage(100);
	a.takeDamage(10);
	a.guardGate();
	return 0;
}

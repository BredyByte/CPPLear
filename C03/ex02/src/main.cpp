#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap a("Pablo");
	FragTrap b("Davyd");
	ScavTrap c("Maria");

	a = b;
	c.guardGate();
	a.attack(b.getName());
	a.highFivesGuys();
	c.takeDamage(123);
	c.beRepaired(123);
	return 0;
}

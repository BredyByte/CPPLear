#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap a("Pablo");
	FragTrap b("Davyd");
	ScavTrap c;

	c.guardGate();
	a.attack(b.getName());
	b.attack(a.getName());
	c.attack(a.getName());
	b.highFivesGuys();
	b.takeDamage(123);
	b.highFivesGuys();
	c.takeDamage(123);
	c.beRepaired(123);
	return 0;
}

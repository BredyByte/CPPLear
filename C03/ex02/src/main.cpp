#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap a("Pablo");
	FragTrap b("Davyd");
	FragTrap g("OTHERDAVYD");
	ScavTrap c;
	ScavTrap p("ÑOkis");

	c = p;
	b = g;
	c.guardGate();
	a.attack(b.getName());
	std::cout << "______________________" << std::endl;
	b.attack(a.getName());
	c.attack(a.getName());
	b.highFivesGuys();
	b.takeDamage(123);
	b.highFivesGuys();
	std::cout << "______________________" << std::endl;
	c.takeDamage(123);
	c.beRepaired(123);
	return 0;
}

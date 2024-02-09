#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a("DIAMOND");
	DiamondTrap b("DIAMOND2");

	a = b;
	a.attack("SOMEONE");
	a.takeDamage(1);
	a.takeDamage(1);
	a.takeDamage(1);
	a.beRepaired(10);
	a.takeDamage(10);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();
	return 0;
}


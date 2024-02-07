#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap a("Pablo");
	FragTrap b("Davyd");

	a = b;
	a.attack(b.getName());
	a.highFivesGuys();
	return 0;
}

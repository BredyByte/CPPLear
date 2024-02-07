#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap a("Pablo");
	ScavTrap b("Davyd");

	a = b;
	a.guardGate();
	return 0;
}

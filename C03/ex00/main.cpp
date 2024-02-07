#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Davyd");
	ClapTrap b("Pablo");

	b.attack(a.getName());
	return 0;
}

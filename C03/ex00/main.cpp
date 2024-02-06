#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Davyd");
	ClapTrap b(a);

	b.attack(a.getName());
	return 0;
}

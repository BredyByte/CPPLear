#include "HumanA.hpp"
#include "Weapon.hpp"

/*  */

HumanA::HumanA(std::string name, Weapon& weapon): _weapon(weapon) {
	_name = name;
	//_weapon.setType(weapon.getType());
}

HumanA::~HumanA() {

}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

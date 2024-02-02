#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::Zombie( std::string name) {
	SetName(name);
}

Zombie::~Zombie() {
	std::cout << "Zombie: " << _name << " died again" << std::endl;
}

void Zombie::announce() {
	std ::cout << ((_name == "Foo") ? "" : "<" ) << _name << ((_name == "Foo") ? "" : ">:") << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName( std::string name ) {
	_name = name;
	std::cout << "Zombie: " << _name << " has risen" << std::endl;
}


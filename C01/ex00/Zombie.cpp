#include "Zombie.hpp"

Zombie::Zombie( std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "Zombie: " << this->_name << " is dead" << std::endl;
}

void Zombie::announce() {
	std ::cout << ((this->_name == "Foo") ? "" : "<" ) << this->_name << ((this->_name == "Foo") ? "" : ">:") << " BraiiiiiiinnnzzzZ..." << std::endl;
}


#include "Character.hpp"

AMateria* Character::_worldStack[100] = {NULL};
int Character::_worldStackCurr = 0;

Character::Character() : _curr(0), _name("Nameless") {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) :  _curr(0), _name(name) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
	}
}

Character::Character(Character& other) {
	if (this != &other) {
		for (int i = 0; i < MAX_INVENTORY && other._inventory[i] != NULL; i++) {
			this->_inventory[i] = other._inventory[i]->clone();
		}
		this->_name = other._name;
		this->_curr = other._curr;
	}
}

Character& Character::operator=(Character& other) {
	if (this != &other) {
		for (int i = 0; i < MAX_INVENTORY && other._inventory[i] != NULL; i++) {
			if (this->_inventory[i] != NULL) {
				delete this->_inventory[i];
			}
			this->_inventory[i] = other._inventory[i]->clone();
		}
		this->_name = other._name;
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::resetWorldStack () {
	for (int i = 0; i < MAX_WORLD_OVERFLOW; i++) {
		if (_worldStack[i] != NULL) {
			delete _worldStack[i];
			_worldStack[i] = NULL;
		}
	}
	_worldStackCurr = 0;
}

AMateria* Character::getWorldStack(int idx) {
	if (idx < 0 || idx >= MAX_WORLD_OVERFLOW || _worldStack[idx] == NULL) {
		std::cout << "Invalid index" << std::endl;
		return NULL;
	}
	_worldStackCurr--;
	AMateria* ret = _worldStack[idx];
	_worldStack[idx] = NULL;
	return ret;
}

void Character::equip(AMateria* m) {
	if (_curr >= MAX_INVENTORY) {
		std::cout << this->getName() << " : My inventory is full" << std::endl;
		if (_worldStackCurr >= MAX_WORLD_OVERFLOW) {
			std::cout << "World stack is full" << std::endl;
			delete m;
			return ;
		}
		_worldStack[_worldStackCurr] = m->clone();
		_worldStackCurr++;
		delete m;
		return ;
	}
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m->clone();
			_curr++;
			delete m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_INVENTORY) {
		std::cout << this->getName() << " : Invalid index" << std::endl;
		return ;
	}
	else if (!_inventory[idx]) {
		std::cout << this->getName() << " : This slot is empty" << std::endl;
		return ;
	}
	else if (_worldStackCurr >= 100) {
		std::cout << "World stack is full" << std::endl;
		delete _inventory[idx];
		return ;
	}
	_worldStack[_worldStackCurr] = _inventory[idx];
	_worldStackCurr++;
	_curr--;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= MAX_INVENTORY) {
		std::cout << this->getName() << " : Invalid index" << std::endl;
		return ;
	}
	else if (!_inventory[idx]) {
		std::cout << this->getName() << " : This slot is empty" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

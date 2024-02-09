#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog: virtual public Animal {
public:
	Dog();
	Dog(std::string type);
	Dog(Dog& other);
	~Dog();
	Dog &operator=(const Dog &other);

	void makeSound() const;
};

#endif

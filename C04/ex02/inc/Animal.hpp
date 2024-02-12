#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual ~Animal() = 0;

protected:
	Animal();
	Animal(std::string type);
	Animal(Animal &other);
	Animal &operator=(const Animal &other);
	std::string _type;
};

#endif

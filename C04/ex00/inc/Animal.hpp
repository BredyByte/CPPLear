#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	Animal();
	Animal(std::string type);
	Animal(Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);

	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif

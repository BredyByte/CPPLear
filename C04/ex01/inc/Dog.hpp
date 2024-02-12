#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal {
public:
	Dog();
	Dog(std::string type);
	Dog(Dog& other);
	~Dog();
	Dog &operator=(const Dog &other);

	void makeSound() const;
private:
	Brain* _brain;
};

#endif

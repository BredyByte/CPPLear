#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &other);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif

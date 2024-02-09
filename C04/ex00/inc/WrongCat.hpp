#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal {
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(WrongCat& other);
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif

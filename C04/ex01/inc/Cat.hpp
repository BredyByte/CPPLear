#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal {
public:
	Cat();
	Cat(std::string type);
	Cat(Cat& other);
	~Cat();
	Cat &operator=(const Cat &other);

	void makeSound() const;
private:
	Brain* _brain;
};
#endif

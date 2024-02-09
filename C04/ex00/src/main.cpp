#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Dog Type: " << j->getType() << " " << std::endl;
	std::cout << "Cat Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "_______________________________" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Wrong Animal Type: " << wrong->getType() << " " << std::endl;
	std::cout << "Wrong Cat Type: " << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();


	std::cout << "_______________________________" << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
	return 0;
}

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
	const int numAnimal = 10;
	Animal** animals = new Animal*[numAnimal];

	std::cout << "__________________CATS_CONSTRUCTORS__________________" << std::endl;
	for (int i = 0; i < numAnimal / 2; i++) {
		animals[i] = new Cat();
	}

	std::cout << "__________________DOGS_CONSTRUCTORS__________________" << std::endl;
	for (int i = numAnimal / 2; i < numAnimal; i++) {
		animals[i] = new Dog();
	}

	for (int i = 0; i < numAnimal; i++) {
		delete animals[i];
	}
	delete[] animals;

	return 0;
}

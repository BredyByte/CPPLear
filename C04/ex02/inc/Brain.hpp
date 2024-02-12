#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

class Brain {
public:
	Brain();
	Brain(Brain& other);
	Brain& operator=(Brain& other);
	~Brain();
private:
	std::string _ideas[100];
};

#endif

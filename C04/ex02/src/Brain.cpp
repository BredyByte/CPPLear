#include "Brain.hpp"

template <typename T, size_t N>
size_t arraylen(const T (&)[N]) {
    return N;
}

std::string generateRandomIdea() {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string randomIdea;

    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % characters.length();
        randomIdea += characters[randomIndex];
    }

    return randomIdea;
}

Brain::Brain() {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        std::string randomIdea = generateRandomIdea();
        _ideas[i] = randomIdea;
    }
	std::cout << "🧠✅ with 100 ideas..." << std::endl;
}

Brain::Brain(Brain& other) {
	size_t len = arraylen(other._ideas);
	for (int i = 0; i < (int)len; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "🧠✅ with 100 ideas..." << std::endl;
}

Brain& Brain::operator=(Brain& other) {
	size_t len = arraylen(other._ideas);
	for (int i = 0; i < (int)len; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "🧠❌ with 100 ideas..." << std::endl;
}

/*
	Brain(Brain& other);
	Brain& operator=(Brain& other);
	~Brain(); */

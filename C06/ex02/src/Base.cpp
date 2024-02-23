#include "Base.hpp"

int generateRandomRange(int min, int max) {
	static bool init = false;
	if (!init) {
		srand(static_cast<unsigned int>(time(0)));
		init = true;
	}
	return min + rand() % (max - min + 1);
}

Base* generate() {
	switch (generateRandomRange(1, 3)) {
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
		default:
			return NULL;
	}

}

void identify(Base* p) {
	if (p == NULL) {
		std::cout << "NULL" << std::endl;
		return;
	}
	else if (p == dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (p == dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (p == dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Unknown" << std::endl;
	}
}

void identify(Base& p) {
	if (&p == dynamic_cast<A*>(&p)) {
		std::cout << "A" << std::endl;
	}
	else if (&p == dynamic_cast<B*>(&p)) {
		std::cout << "B" << std::endl;
	}
	else if (&p == dynamic_cast<C*>(&p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Unknown" << std::endl;
	}
}



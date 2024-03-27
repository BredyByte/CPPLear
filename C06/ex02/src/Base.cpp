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
		std::cout << "OK: NULL" << std::endl;
		return;
	}
	else if (p == dynamic_cast<A*>(p)) {
		std::cout << "OK: A by pointer" << std::endl;
	}
	else if (p == dynamic_cast<B*>(p)) {
		std::cout << "OK: B by pointer" << std::endl;
	}
	else if (p == dynamic_cast<C*>(p)) {
		std::cout << "OK: C by pointer" << std::endl;
	}
	else {
		std::cout << "ERROR: Unknown" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "OK: A by reference" << std::endl;
	}
	catch(const std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "OK: B by reference" << std::endl;
		}
		catch(const std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "OK: C by reference" << std::endl;
			}
			catch(const std::exception &e) { }
		}
	}
}



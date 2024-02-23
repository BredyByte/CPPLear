#include "Base.hpp"

Base* generate() {
	return new A;
}

void identify(Base* p) {
	(void) p;
}

void identify(Base& p) {
	(void) p;
}



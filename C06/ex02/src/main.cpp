#include "Base.hpp"

int main() {
	Base* base = generate();
	identify(base);
	identify(*base);
	return 0;
}

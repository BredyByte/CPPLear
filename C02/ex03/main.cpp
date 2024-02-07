#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point point(1,1);

	std::cout << bsp(a, b ,c, point) << std::endl;
	return 0;
}

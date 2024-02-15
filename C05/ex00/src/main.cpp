#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a("Davyd", 145);

	std::cout << a << std::endl;
	a.incGrade();
	std::cout << a << std::endl;
	return 0;
}

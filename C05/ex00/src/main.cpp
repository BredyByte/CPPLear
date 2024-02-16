#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Davyd", 150);
		a.incGrade();
		a.incGrade();
		a.incGrade();
		a.incGrade();
		a.decrGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat p("Pablo", 1);
		p.incGrade();
		p.incGrade();
		p.decrGrade();
		p.decrGrade();
		p.decrGrade();
		std::cout << p << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

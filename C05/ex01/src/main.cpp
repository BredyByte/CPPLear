#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat d("Davyd", 150);
		std::cout << d << std::endl;

		Bureaucrat p("Pablo", 1);
		std::cout << p << std::endl;

		Form f("Some", 145, 12);
		f.beSigned(p);
		std::cout << f << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

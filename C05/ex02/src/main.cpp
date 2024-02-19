#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat d("Davyd", 140);
		std::cout << d << std::endl;

		Bureaucrat p("Pablo", 45);
		std::cout << p << std::endl;

		RobotomyRequestForm f("home");
		f.signAndExec(p);
		std::cout << f << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

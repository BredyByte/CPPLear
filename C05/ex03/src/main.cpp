#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	AForm* form = NULL;
	try {
		Intern intern;
		form = intern.makeForm("form2", "target");
		Bureaucrat lala("Lalita", 2);
		form->signAndExec(lala);

		delete form;
	}
	catch (std::exception& e) {
		delete form;
		std::cout << e.what() << std::endl;
	}
	return 0;
}

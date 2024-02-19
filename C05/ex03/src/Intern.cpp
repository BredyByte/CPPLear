#include "Intern.hpp"

const std::string Intern::formNames[arrSize] = {"Unknown", "PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

Intern::Intern() {

}

Intern::Intern(Intern& other) {
	(void) other;
}

Intern& Intern::operator=(Intern& other) {
	(void) other;
	return *this;
}

Intern::~Intern() {

}

AForm* Intern::makeForm(std::string name, std::string target) {
	FuncPtr f[] = {&Intern::func0, &Intern::func1, &Intern::func2, &Intern::func3};
	int i = 0;
	while (formNames[i] != name && i < arrSize) {
		i++;
	}
	return (this->*f[i % arrSize])(target);
}

AForm* Intern::func0(std::string target) {
	(void) target;
	throw Intern::UnknownFormException();
	return new PresidentialPardonForm(target);
}

AForm* Intern::func1(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::func2(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::func3(std::string target) {
	return new ShrubberyCreationForm(target);
}

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

AForm& Intern::makeForm(std::string name, std::string target) {
	(void) target;
	(void) name;
	AForm* (Intern::*complain_ptr[3])(std::string target) = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};
	for(int i = 0; formNames[i] == name; i++) {

	}
	return *(this->*complain_ptr[i])(target);
}



AForm* Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
	return *(new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(std::string target) {
	return *(new ShrubberyCreationForm(target));
}

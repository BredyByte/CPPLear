#include "Intern.hpp"

const std::string Intern::formNames[] = {"form1", "form2", "form3"};
const int Intern::arrSize = 3;


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

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
    for (int i = 0; i < arrSize; ++i) {
        if (formNames[i] == name) {
            std::cout << "Intern creates Form: " << name << std::endl;
            return (this->*functionPointers[i])(target);
        }
    }
    throw UnknownFormException();
}

AForm* Intern::form1(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::form2(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::form3(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

Intern::FuncPtr Intern::functionPointers[] = {
    &Intern::form1,
    &Intern::form2,
    &Intern::form3
};

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default target") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other) {
    this->_target = other.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
    this->_target = other.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::_execute(Bureaucrat const & executor) const {
	(void) executor;
	std::cout << std::endl << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl << std::endl;
}

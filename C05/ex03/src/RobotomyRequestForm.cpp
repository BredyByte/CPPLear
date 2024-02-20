#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default target") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other) {
    this->_target = other.getTarget();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
    this->_target = other.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::_execute(Bureaucrat const & executor) const {
	(void) executor;
	srand(time(0));
	std::cout << std::endl << "Makes some drilling noises..." << std::endl;
	bool success = (rand() % 100) < 50;
	if (success) {
        std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else {
		std::cout << "Robotomy on " << _target << " failed." << std::endl;
	}
	std::cout << std::endl;
}

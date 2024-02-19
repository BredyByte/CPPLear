#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat() : _name("Deff"), _grade(150) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(Bureaucrat& other) {
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return  *this;
}

std::string const Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incGrade() {
	_grade--;
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrGrade() {
	_grade++;
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(std::string formName) {
	std::cout << "Bureaucrat " << this->getName() << " has signed the Form: " << formName << std::endl;
}

void Bureaucrat::executeForm(std::string formName) const {
    std::cout << "Bureaucrat " << this->getName() << " has executed the Form: " << formName << std::endl;
}

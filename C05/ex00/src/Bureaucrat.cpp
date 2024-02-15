#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {

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
}

void Bureaucrat::decrGrade() {
	_grade++;
}

#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, Form& obj) {
    os << "Form: " << obj.getName() << ". Min required grade to sign it: " << obj.getGradeToSign() << ". Min required grade to exeute it: " <<  obj.getGradeToExecute() << ". With current status: " << ((obj.formIsSigned()) ? "Signed" : "Unsigned");
    return os;
}

void ConstructorPrint(Form& obj) {
	std::cout << "__________________________________________________" << std::endl;
	std::cout << "Form with name: " << obj.getName() << std::endl;
	std::cout << "Min. grade to sign: " << obj.getGradeToSign() << std::endl;
	std::cout << "Min. grade to execute: " << obj.getGradeToExecute() << std::endl;
	std::cout << "Has been created successfully!!" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;

}

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {
	ConstructorPrint(*this);
}

Form::Form(std::string name, int toSign, int toExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(toSign), _gradeRequiredToExecute(toExecute) {
	if (_gradeRequiredToSign < 1) {
		throw Form::GradeTooHighException();
	}
	else if (_gradeRequiredToSign > 150) {
		throw Form::GradeTooLowException();
	}

	if (_gradeRequiredToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	else if (_gradeRequiredToExecute > 150) {
		throw Form::GradeTooLowException();
	}
	ConstructorPrint(*this);
}

Form::Form(Form& other) : _name(other.getName()), _isSigned(other.formIsSigned()), _gradeRequiredToSign(other.getGradeToSign()), _gradeRequiredToExecute(other.getGradeToExecute()) {
	ConstructorPrint(*this);
}

Form& Form::operator=(Form& other) {
	if (this != &other) {
		_isSigned = other.formIsSigned();
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form Destructor" << std::endl;
}

std::string	Form::getName() {
	return _name;
}

int	Form::getGradeToSign() {
	return _gradeRequiredToSign;
}

int	Form::getGradeToExecute() {
	return _gradeRequiredToExecute;
}

bool Form::formIsSigned() {
	return _isSigned;
}

void Form::beSigned(Bureaucrat& obj) {
	if (obj.getGrade() <= this->getGradeToSign()) {
		_isSigned = true;
		obj.signForm(this->getName());
		return ;
	}
	std::cout << "Bureaucrat " << obj.getName() << " can't sign the Form: " << this->getName() << ", his grade is " << obj.getGrade() << ", form min. required grade is " << this->getGradeToSign() << std::endl;
	throw Form::GradeTooLowException();
}

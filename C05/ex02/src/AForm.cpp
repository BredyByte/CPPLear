#include "AForm.hpp"

std::ostream& operator<<(std::ostream& os, AForm& obj) {
    os << "Form: " << obj.getName() << ". Min required grade to sign it: " << obj.getGradeToSign() << ". Min required grade to exeute it: " <<  obj.getGradeToExecute() << ". With current status: " << ((obj.formIsSigned()) ? "Signed" : "Unsigned");
    return os;
}

void ConstructorPrint(AForm& obj) {
	std::cout << std::endl << "               " << obj.getName() << ":" << "               " << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	std::cout << "Form with name: " << obj.getName() << std::endl;
	std::cout << "Min. grade to sign: " << obj.getGradeToSign() << std::endl;
	std::cout << "Min. grade to execute: " << obj.getGradeToExecute() << std::endl;
	std::cout << "Has been created successfully!!" << std::endl;
	std::cout << "__________________________________________________" << std::endl << std::endl;
}

AForm::AForm() : _name("DefaultForm"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {
	ConstructorPrint(*this);
}

AForm::AForm(std::string name, int toSign, int toExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(toSign), _gradeRequiredToExecute(toExecute) {
	if (_gradeRequiredToSign < 1) {
		throw AForm::GradeTooHighException();
	}
	else if (_gradeRequiredToSign > 150) {
		throw AForm::GradeTooLowException();
	}

	if (_gradeRequiredToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	else if (_gradeRequiredToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
	ConstructorPrint(*this);
}

AForm::AForm(AForm& other) : _name(other.getName()), _isSigned(other.formIsSigned()), _gradeRequiredToSign(other.getGradeToSign()), _gradeRequiredToExecute(other.getGradeToExecute()) {
	ConstructorPrint(*this);
}

AForm& AForm::operator=(AForm& other) {
	if (this != &other) {
		_isSigned = other.formIsSigned();
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "Form Destructor" << std::endl;
}

std::string	AForm::getName() {
	return _name;
}

int	AForm::getGradeToSign() {
	return _gradeRequiredToSign;
}

int	AForm::getGradeToExecute() {
	return _gradeRequiredToExecute;
}

bool AForm::formIsSigned() {
	return _isSigned;
}

void AForm::isSignedSetter() {
	_isSigned = true;
}

void AForm::cantExecuteSignExeptPrint(Bureaucrat& obj) {
	std::cout << "Bureaucrat " << obj.getName() << " can't" << ((this->formIsSigned()) ? " execute " : " sign ") << "the Form:" << this->getName() << ", Bureaucrat's grade is " << obj.getGrade() << ", form's min. required grade to" << ((this->formIsSigned()) ? " execute " : " sign ") <<  "is " << this->getGradeToExecute() << std::endl;
	throw AForm::GradeTooLowException();
}

void AForm::signAndExec(Bureaucrat& obj) {
	if (obj.getGrade() <= this->getGradeToSign() && !this->formIsSigned()) {
		isSignedSetter();
		obj.signForm(this->getName());
	}
	if (this->formIsSigned()) {
		if (obj.getGrade() <= this->getGradeToExecute()) {
			obj.executeForm(this->getName());
			this->execute(obj);
			return ;
		}
	}
	this->cantExecuteSignExeptPrint(obj);
}

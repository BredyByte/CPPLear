#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
	std::string const	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int 			_gradeRequiredToExecute;

public:
	Form();
	Form(std::string name, int toSign, int toExecute);
	~Form();
	Form(Form& other);
	Form& operator=(Form& other);

	std::string	getName();
	int			getGradeToSign();
	int			getGradeToExecute();
	bool		formIsSigned();
	void 		beSigned(Bureaucrat& obj);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form Error: Grade is to high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw () {
			return "Form Error: Grade is to low";
		}
	};
};

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif

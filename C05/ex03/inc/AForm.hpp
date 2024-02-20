#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm {
private:
	virtual void		_execute(Bureaucrat const & executor) const = 0;

	std::string const	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int 			_gradeRequiredToExecute;

public:
	AForm();
	AForm(std::string name, int toSign, int toExecute);
	virtual ~AForm();
	AForm(AForm& other);
	AForm& operator=(AForm& other);

	std::string			getName();
	int					getGradeToSign();
	int					getGradeToExecute();
	bool				formIsSigned();

	void				cantExecuteSignExeptPrint(Bureaucrat& obj);
	void				signAndExec(Bureaucrat& obj);

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

std::ostream& operator<<(std::ostream& os, AForm& obj);

#endif

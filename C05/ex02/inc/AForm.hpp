#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm {
private:
	std::string const	_name;
	bool				_isSigned;
	const int			_gradeRequiredToSign;
	const int 			_gradeRequiredToExecute;

public:
	AForm();
	AForm(std::string name, int toSign, int toExecute);
	~AForm();
	AForm(AForm& other);
	AForm& operator=(AForm& other);

	std::string			getName();
	int					getGradeToSign();
	int					getGradeToExecute();
	bool				formIsSigned();
	void				isSignedSetter(bool val);

	void				cantExecuteSignExeptPrint(Bureaucrat& obj);
	void				signAndExec(Bureaucrat& obj);
	virtual void		execute(Bureaucrat const & executor) = 0;

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

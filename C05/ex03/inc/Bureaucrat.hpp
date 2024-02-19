#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat& other);
	std::string const getName() const;
	int getGrade() const;
	void incGrade();
	void decrGrade();
	void signForm(std::string formName);
	void executeForm(std::string formName) const; 

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw () {
			return "Bureaucrat Error: Grade is too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw () {
			return "Bureaucrat Error: Grade is too low";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif

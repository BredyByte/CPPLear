#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif

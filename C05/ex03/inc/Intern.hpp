#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	static const int arrSize = 4;
	static const std::string formNames[arrSize];
	Intern();
	Intern(Intern& other);
	Intern& operator=(Intern& other);
	~Intern();

	AForm& makeForm(std::string name, std::string target);
	AForm* makePresidentialPardonForm(std::string target);
	AForm*  makeRobotomyRequestForm(std::string target);
	AForm*  makeShrubberyCreationForm(std::string target);

	class UnknownFormException : public std::exception {
		virtual const char* what() const throw() {
			return "Unknown form name.";
		}
	};
};
#endif

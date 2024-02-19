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

    AForm* makeForm(std::string name, std::string target);
    AForm* func1(std::string target);
    AForm* func2(std::string target);
    AForm* func3(std::string target);
	AForm* func0(std::string target);

    class UnknownFormException : public std::exception {
        virtual const char* what() const throw() {
            return "Unknown form name.";
        }
    };
private:
    typedef AForm* (Intern::*FuncPtr)(std::string target);
    static FuncPtr functionPointers[arrSize];
};

#endif

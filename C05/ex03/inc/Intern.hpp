#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern& other);
    Intern& operator=(Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target) const;

    class UnknownFormException : public std::exception {
    public:
        const char* what() const throw() {
            return "Unknown form name.";
        }
    };

private:
    static const std::string formNames[];
    static const int arrSize;

    typedef AForm* (Intern::*FuncPtr)(const std::string& target) const;
    static FuncPtr functionPointers[];

    AForm* form3(const std::string& target) const;
    AForm* form2(const std::string& target) const;
    AForm* form1(const std::string& target) const;
};
#endif

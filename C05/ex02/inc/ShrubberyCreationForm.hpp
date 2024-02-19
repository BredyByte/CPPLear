#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	std::string getTarget() const;
	void		execute(Bureaucrat const & executor) const;
};

#endif

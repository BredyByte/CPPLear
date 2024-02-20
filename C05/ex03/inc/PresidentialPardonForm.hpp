#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	void		_execute(Bureaucrat const & executor) const;
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(PresidentialPardonForm& other);
	~PresidentialPardonForm();

	std::string getTarget() const;
};

#endif

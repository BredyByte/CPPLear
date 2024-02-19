#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(RobotomyRequestForm& other);

	void		execute(Bureaucrat const & executor);
};

#endif

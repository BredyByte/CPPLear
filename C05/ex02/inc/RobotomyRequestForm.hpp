#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
	void		_execute(Bureaucrat const & obj) const;
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string getTarget() const;
};

#endif

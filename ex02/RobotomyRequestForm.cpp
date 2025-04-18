#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called with target: " << target << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator not allowed" << std::endl;
	(void) rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw IsNotSignedException();
    else if (executor.getGrade() > _exeGrade)
        throw GradeTooLowException();
    std::cout << "Execute form\n";
}

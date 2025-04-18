#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called with target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator not allowed" << std::endl;
	(void) rhs;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw IsNotSignedException();
    else if (executor.getGrade() > _exeGrade)
        throw GradeTooLowException();
    std::cout << "Execute form\n";
}

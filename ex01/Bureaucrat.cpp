#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("Random"), _grade(150)
{
    // std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called with name : " << name << " and grade : " << grade << std::endl;
		if (_grade > 150)
			throw GradeTooLowException();
		else if (_grade < 1)
			throw GradeTooHighException();			
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    // std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat \"" << _name << "\" destructor called" << std::endl;
}

std::string const Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
		std::cout << SMYELLOW << "Incrementing " << _name << "\'s grade..." << RESET << std::endl;
		if ((_grade - 1) < 1)
			throw GradeTooHighException();
		else
			_grade--;
}

void Bureaucrat::decrementGrade(void)
{
		std::cout << SMYELLOW << "Decrementing " << _name << "\'s grade..." << RESET << std::endl;
		if ((_grade + 1) > 150)
			throw GradeTooLowException();
		else
			_grade++;	
}

void Bureaucrat::signForm(Form &form)
{
	std::string reason;

	form.beSigned(*this);

	// if (_grade > form.getSignGrade() || form.getSigned())
	// {
	// 	if (form.getSigned())
	// 		reason = "it's already signed";
	// 	else
	// 		reason = _name + "\'s grade is too low";
	// 	std::cout << _name << " couldn\'t sign " << form.getName() << " because " << reason << std::endl; 
	// }
	// else if (_grade <= form.getSignGrade() && form.getSigned())
	// 	std::cout << _name << " couldn\'t sign " << form.getName() << " because it's already signed" << std::endl; 
	// else
	// {
	// 	form.beSigned(*this);
	// 	std::cout << _name << " signed " << form.getName() << std::endl;
	// }
}

std::ostream & operator<<(std:: ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

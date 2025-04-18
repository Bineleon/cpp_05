#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    public:
	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class IsSignedException: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
    class IsSignedException: public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\033[0;31mthe form is already signed !\033[0m");
		}
	};
        Form(void);
        Form(const Form& src);
		Form(std::string name, int const signGrade, int const exeGrade);
        Form& operator=(const Form& rhs);
        ~Form(void);
		std::string const getName(void) const;
		bool getSigned(void) const;
		int	getSignGrade(void) const;
		int	getExeGrade(void) const;
		void beSigned(Bureaucrat const & b);


    private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _exeGrade;

};

std::ostream & operator<<(std:: ostream & o, Form const & rhs);


# define RESET "\033[0m"
# define SMRED "\033[0;31m"
# define SMGREEN "\033[0;32m"
# define SMYELLOW "\033[0;33m"
# define SMBLUE "\033[0;34m"
# define SMMAGENTA "\033[0;35m"
# define SMCYAN "\033[0;36m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

#endif

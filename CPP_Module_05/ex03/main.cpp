#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::string b_name = "Bernie";
	Bureaucrat *small = NULL, *big = NULL;

	try
	{
		small = new Bureaucrat("Stinky", Bureaucrat::_MIN_GRADE);
		std::cout << *small;
	}
	catch (std::exception &e)
	{
		delete (small);
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try
	{
		big = new Bureaucrat("Boss", Bureaucrat::_MAX_GRADE);
		std::cout << *big;
	}
	catch (std::exception &e)
	{
		delete (small);
		delete (big);
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	Intern 		intern;
	std::string form_name;
	getline(std::cin, form_name);


	AForm *form = intern.makeForm(form_name, "target");
	if (form)
	{
		big->signForm(form);
		big->executeForm(form);
		delete form;
	}

	delete (small);
	delete (big);
}

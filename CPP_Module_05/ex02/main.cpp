#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	try
	{
		std::string target;

		std::cout << "Enter target of form1:" << std::endl;

		std::getline(std::cin, target);
		AForm *form1, *form2, *form3;
		
		PresidentialPardonForm f1(target);
		form1 = &f1;
		std::cout << form1 << std::endl;

		std::cout << "Enter target of form2:" << std::endl;
		std::getline(std::cin, target);
		RobotomyRequestForm f2(target);
		form2 = &f2; 
		std::cout << form2 << std::endl;


		std::cout << "Enter target of form3:" << std::endl;
		std::getline(std::cin, target);
		ShrubberyCreationForm f3(target);
		form3 = &f3;
		std::cout << form3 << std::endl;

		small->executeForm(form1);
		big->executeForm(form2);
		small->executeForm(form3);

		small->signForm(form1);
		big->signForm(form1);
		small->signForm(form2);
		big->signForm(form2);
		small->signForm(form3);
		big->signForm(form3);
		
		small->executeForm(form1);
		big->executeForm(form1);
		small->executeForm(form2);
		big->executeForm(form2);
		small->executeForm(form3);
		big->executeForm(form3);
		
	}
	catch (std::exception &e)
	{
		std::cerr << "error: " << e.what() << std::endl;
	}
	delete (small);
	delete (big);
}

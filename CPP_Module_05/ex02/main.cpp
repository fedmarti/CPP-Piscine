#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	int	grade;
	std::string b_name = "Bernie";
	Bureaucrat *bur;

	std::cout << "input bureaucrat " << b_name << "'s grade" << std::endl;
	std::cin >> grade;
	try
	{
		bur = new Bureaucrat(b_name, grade);
		std::cout << *bur;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		delete (bur);
		return (1);
	}

	try
	{
		int e_grade, s_grade;

		std::cout << "input required execution grade " << std::endl;
		std::cin >> e_grade;
	
		std::cout << "input required signing grade " << std::endl;
		std::cin >> s_grade;
		AForm form("boring stuff", e_grade, s_grade);
		while (!form.getSigned())
		{
			bur->signForm(form);
			if (!form.getSigned() && bur->getGrade() > 1)
			{
				std::cout << bur->getName() << "grade incremented" << std::endl;
				bur->incrementGrade();
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "exception caught:" << e.what() << std::endl;
	}
	delete (bur);
	return (0);
}

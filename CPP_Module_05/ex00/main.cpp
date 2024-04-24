#include "Bureaucrat.hpp"

int main()
{
	int	grade;
	std::string b_name = "Bernie";
	Bureaucrat *bur;
	int err = 0;

	std::cout << "input bureaucrat " << b_name << "'s grade" << std::endl;
	std::cin >> grade;
	try
	{
		bur = new Bureaucrat(b_name, grade);
		std::cout << *bur;
		bur->decrementGrade();
		std::cout << *bur;
		while (1)
		{
			bur->incrementGrade();
			std::cout << *bur;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		err = 1;
	}
	delete (bur);
	return (err);
}

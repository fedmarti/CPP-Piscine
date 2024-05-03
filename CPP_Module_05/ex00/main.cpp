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
		std::cout << "Allocation Successful:\n" << *bur;
	}
	catch (std::exception &e)
	{
		std::cerr << "Couldn't allocate Bureaucrat because: " << e.what() << std::endl;
		return (1);
	}
	try
	{
		std::cout << "Decrementing the grade once:\n";
		bur->decrementGrade();
		std::cout << *bur;
		while (1)
		{
			std::cout << "Now incrementing grade:\n";
			bur->incrementGrade();
			std::cout << *bur;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete (bur);
	return (err);
}

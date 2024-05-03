/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:59:30 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/03 17:31:20 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm("Robotomy Request", 45, 72), _target(target)
{
	;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	;
}

const std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const throw( GradeTooLowException, NotSignedException )
{
	if (!getSigned())
		throw(NotSignedException());
	if (executor.getGrade() > getExecutionGrade())
		throw(GradeTooLowException());

	std::cout << "*Drilling noises*\n...\n";
	srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << _target << " has been robotomized";
	}
	else
		std::cout << "the robotomy has failed";
	std::cout << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("n\a", 0, 0)
{
	;
}
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm & ref ) : AForm("n\a", 0, 0)
{
	(void)ref;
}
RobotomyRequestForm & RobotomyRequestForm::operator = ( RobotomyRequestForm & rhs )
{
	(void)rhs;
	return (*this);
}
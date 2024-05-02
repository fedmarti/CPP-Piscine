/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:59:30 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/01 01:26:43 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

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
	if (executor.getGrade() > getExecutionGrade())
		throw(GradeTooLowException());
	if (!getSigned())
		throw(NotSignedException());

	std::cout << "*Drilling noises*\n...\n";
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
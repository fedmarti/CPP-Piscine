/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:07:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/24 02:09:26 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( Bureaucrat & ref ) : _name(ref.getName()), _grade(ref.getGrade())
{
	;
}

Bureaucrat::Bureaucrat( void ) : _name("void"), _grade(1)
{
	;
}
Bureaucrat::~Bureaucrat( void )
{
	;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat( std::string name, int grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException): _name(name), _grade(Bureaucrat::_MIN_GRADE)
{
	if (grade > Bureaucrat::_MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < Bureaucrat::_MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade = grade;
}

unsigned short	Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

std::string	Bureaucrat::getName( void ) const
{
	return (_name);
}

void	Bureaucrat::incrementGrade( void ) throw(Bureaucrat::GradeTooHighException)
{
	if ( _grade <= Bureaucrat::_MAX_GRADE )
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade--;
}

void	Bureaucrat::decrementGrade( void ) throw(Bureaucrat::GradeTooLowException)
{
	if ( _grade >= Bureaucrat::_MIN_GRADE )
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade++;
}

void	Bureaucrat::signForm( Form &form ) const
{
	std::cout << _name;
	try
	{
		form.beSigned(*this);
		std::cout << " signed " << form.getName();
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << " couldn't sign " << form.getName() << " because " << e.what();
	}
	std::cout << std::endl;
}

std::ostream & operator << ( std::ostream & output, Bureaucrat & rhs )
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (output);
}

Bureaucrat & Bureaucrat::operator = ( Bureaucrat &rhs )
{
	(void)rhs;
	return (*this);
}

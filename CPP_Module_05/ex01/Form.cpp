/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:22:10 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/24 02:56:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("n/a"), _signed(false), _execution_grade(150), _signing_grade(150)
{
	;
}

Form::Form( Form & ref ) : _name(ref.getName()), _signed(ref.getSigned()), _execution_grade(ref.getExecutionGrade()), _signing_grade(ref.getSigningGrade())
{
	;
}

Form::Form( std::string name, int execution_grade, int signing_grade ) throw(GradeTooLowException, GradeTooHighException) : _name(name), _signed(false), _execution_grade(execution_grade), _signing_grade(signing_grade)
{
	if ( _execution_grade < Bureaucrat::_MAX_GRADE || _signing_grade < Bureaucrat::_MAX_GRADE )
		throw (GradeTooHighException());
	if ( _execution_grade > Bureaucrat::_MIN_GRADE || _signing_grade > Bureaucrat::_MIN_GRADE )
		throw (GradeTooLowException());
}

Form::~Form( void )
{
	;
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return ( "Grade too low" );
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
	return ( "Grade too high" );
}

void	Form::beSigned( const Bureaucrat & bur ) throw( GradeTooLowException )
{
	if (bur.getGrade() > _signing_grade)
		throw(GradeTooLowException());
	_signed = true;
}

int	Form::getExecutionGrade( void ) const
{
	return (_execution_grade);
}

int	Form::getSigningGrade( void ) const
{
	return (_signing_grade);	
}

std::string	Form::getName( void ) const
{
	return (_name);
}

bool	Form::getSigned( void ) const
{
	return (_signed);
}
	
Form & Form::operator = ( Form &rhs )
{
	(void)rhs;
	return (*this);
}

std::ostream & operator << ( std::ostream &output, Form rhs )
{
	output << "Form" << rhs.getName() << "\nGrade requirements: Execution " << rhs.getExecutionGrade() << ", Signing " << rhs.getSigningGrade() << std::endl;
	return (output);
}

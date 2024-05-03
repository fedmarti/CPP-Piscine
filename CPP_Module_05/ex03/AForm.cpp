/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:22:10 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/24 02:56:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name("n/a"), _signed(false), _execution_grade(150), _signing_grade(150)
{
	;
}

AForm::AForm( AForm & ref ) : _name(ref.getName()), _signed(ref.getSigned()), _execution_grade(ref.getExecutionGrade()), _signing_grade(ref.getSigningGrade())
{
	;
}

AForm::AForm( std::string name, int execution_grade, int signing_grade ) throw(GradeTooLowException, GradeTooHighException) : _name(name), _signed(false), _execution_grade(execution_grade), _signing_grade(signing_grade)
{
	if ( _execution_grade < Bureaucrat::_MAX_GRADE || _signing_grade < Bureaucrat::_MAX_GRADE )
		throw (GradeTooHighException());
	if ( _execution_grade > Bureaucrat::_MIN_GRADE || _signing_grade > Bureaucrat::_MIN_GRADE )
		throw (GradeTooLowException());
}

AForm::~AForm( void )
{
	;
}

const char *AForm::GradeTooLowException::what( void ) const throw()
{
	return ( "Grade too low" );
}

const char *AForm::GradeTooHighException::what( void ) const throw()
{
	return ( "Grade too high" );
}

const char *AForm::NotSignedException::what( void ) const throw()
{
	return ( "Form not signed yet" );
}

void	AForm::beSigned( const Bureaucrat & bur ) throw( GradeTooLowException )
{
	if (bur.getGrade() > _signing_grade)
		throw(GradeTooLowException());
	_signed = true;
}

int	AForm::getExecutionGrade( void ) const
{
	return (_execution_grade);
}

int	AForm::getSigningGrade( void ) const
{
	return (_signing_grade);	
}

std::string	AForm::getName( void ) const
{
	return (_name);
}

bool	AForm::getSigned( void ) const
{
	return (_signed);
}
	
AForm & AForm::operator = ( AForm &rhs )
{
	(void)rhs;
	return (*this);
}

std::ostream & operator << ( std::ostream &output, AForm *rhs )
{
	output << "AForm " << rhs->getName() << "\nGrade requirements: Execution " << rhs->getExecutionGrade() << ", Signing " << rhs->getSigningGrade() << std::endl;
	return (output);
}

const std::string AForm::FORM_TYPES[Void_FT] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
};
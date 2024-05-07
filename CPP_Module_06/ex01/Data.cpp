/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:07:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/07 19:48:06 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( Data & ref ) : _name(ref.getName()), _grade(ref.getGrade())
{
	;
}

Data::Data( void ) : _name("void"), _grade(1)
{
	;
}
Data::~Data( void )
{
	;
}

const char *Data::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Data::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Data::Data( std::string name, int grade ) throw(Data::GradeTooHighException, Data::GradeTooLowException): _name(name), _grade(Data::_MIN_GRADE)
{
	if (grade > Data::_MIN_GRADE)
		throw (Data::GradeTooLowException());
	else if (grade < Data::_MAX_GRADE)
		throw (Data::GradeTooHighException());
	else
		_grade = grade;
}

unsigned short	Data::getGrade( void ) const
{
	return (_grade);
}

std::string	Data::getName( void ) const
{
	return (_name);
}

void	Data::incrementGrade( void ) throw(Data::GradeTooHighException)
{
	if ( _grade <= Data::_MAX_GRADE )
		throw (Data::GradeTooHighException());
	else
		_grade--;
}

void	Data::decrementGrade( void ) throw(Data::GradeTooLowException)
{
	if ( _grade >= Data::_MIN_GRADE )
		throw (Data::GradeTooLowException());
	else
		_grade++;
}

std::ostream & operator << ( std::ostream & output, Data & rhs )
{
	output << rhs.getName() << ", Data grade " << rhs.getGrade() << std::endl;
	return (output);
}

Data & Data::operator = ( Data &rhs )
{
	(void)rhs;
	return (*this);
}
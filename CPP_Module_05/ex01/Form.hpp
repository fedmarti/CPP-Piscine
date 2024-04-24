/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:29:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/24 02:06:16 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooLowException : public std::exception {
	public:
		const char *what( void ) const throw();	
	};
	class GradeTooHighException : public std::exception {
	public:
		const char *what( void ) const throw();	
	};
	
	~Form( void );
	Form( std::string name, int e_grade, int s_grade ) throw( GradeTooLowException, GradeTooHighException );
	void		beSigned( const Bureaucrat & ) throw( GradeTooLowException );
	int			getExecutionGrade( void ) const;
	int			getSigningGrade( void ) const;
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	
	Form & operator = ( Form &rhs );
private:
	Form( Form &ref );
	Form( void );

	const std::string	_name;
	bool				_signed;
	const int			_execution_grade;
	const int			_signing_grade;
};

std::ostream & operator << ( std::ostream & output, Form rhs );
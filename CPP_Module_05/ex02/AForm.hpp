/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:29:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/30 23:17:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Bureaucrat.hpp"

class AForm
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
	
	virtual ~AForm( void );
	AForm( std::string name, int e_grade, int s_grade ) throw( GradeTooLowException, GradeTooHighException );
	void		beSigned( const Bureaucrat & ) throw( GradeTooLowException );
	int			getExecutionGrade( void ) const;
	int			getSigningGrade( void ) const;
	std::string	getName( void ) const;
	bool		getSigned( void ) const;

	virtual void	execute(Bureaucrat const & executor) const throw( GradeTooLowException ) = 0; 
	
	AForm & operator = ( AForm &rhs );
private:
	AForm( AForm &ref );
	AForm( void );

	const std::string	_name;
	bool				_signed;
	const int			_execution_grade;
	const int			_signing_grade;
};

std::ostream & operator << ( std::ostream & output, AForm rhs );
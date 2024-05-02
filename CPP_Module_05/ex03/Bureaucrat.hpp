/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/30 01:14:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
		public :
		const char * what() const throw();
	};
		class GradeTooLowException : public std::exception {
		public :
		const char * what() const throw();
	};

	Bureaucrat( std::string name, int grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	Bureaucrat( Bureaucrat & );
	~Bureaucrat( void );
	unsigned short	getGrade( void ) const;
	std::string		getName( void ) const;
	void			incrementGrade( void ) throw(Bureaucrat::GradeTooHighException);
	void			decrementGrade( void ) throw(Bureaucrat::GradeTooLowException);
	void			signForm( AForm *form ) const;
	void			executeForm( AForm *form ) const;
	const static int	_MIN_GRADE = 150;
	const static int	_MAX_GRADE = 1;
	
private:
	Bureaucrat & operator = ( Bureaucrat &rhs );
	Bureaucrat( void );

	const std::string	_name;
	unsigned short		_grade;
};

std::ostream & operator << ( std::ostream & output, Bureaucrat & rhs );
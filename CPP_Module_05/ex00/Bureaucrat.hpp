/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/23 23:11:40 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <stdexcept>

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
	~Bureaucrat( void );
	unsigned short	getGrade( void ) const;
	std::string		getName( void ) const;
	void			incrementGrade( void ) throw(Bureaucrat::GradeTooHighException);
	void			decrementGrade( void ) throw(Bureaucrat::GradeTooLowException);
	
private:
	Bureaucrat & operator = ( Bureaucrat &rhs );
	Bureaucrat( Bureaucrat & );
	Bureaucrat( void );

	const std::string	_name;
	unsigned short		_grade;
	const static int	_MIN_GRADE = 150;
	const static int	_MAX_GRADE = 1;
};

std::ostream & operator << ( std::ostream & output, Bureaucrat & rhs );
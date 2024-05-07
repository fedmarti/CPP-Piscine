/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/07 19:48:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <stdexcept>

class Data {
public:
	class GradeTooHighException : public std::exception {
		public :
		const char * what() const throw();
	};
		class GradeTooLowException : public std::exception {
		public :
		const char * what() const throw();
	};

	Data( std::string name, int grade ) throw(Data::GradeTooHighException, Data::GradeTooLowException);
	~Data( void );
	unsigned short	getGrade( void ) const;
	std::string		getName( void ) const;
	void			incrementGrade( void ) throw(Data::GradeTooHighException);
	void			decrementGrade( void ) throw(Data::GradeTooLowException);
	
private:
	Data & operator = ( Data &rhs );
	Data( Data & );
	Data( void );

	const std::string	_name;
	unsigned short		_grade;
	const static int	_MIN_GRADE = 150;
	const static int	_MAX_GRADE = 1;
};

std::ostream & operator << ( std::ostream & output, Data & rhs );
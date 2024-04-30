/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:05 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/30 23:35:41 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	ShrubberyCreationForm( const std::string target );
	~ShrubberyCreationForm( void );
	
	void				execute(Bureaucrat const & executor) const throw( GradeTooLowException );
	const std::string	getTarget( void ) const;
private:
	const std::string	_target;
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm & ref );
	ShrubberyCreationForm & operator = ( ShrubberyCreationForm & rhs );
};

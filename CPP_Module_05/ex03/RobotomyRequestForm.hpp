/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:28 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/01 01:15:57 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm( const std::string target );
	~RobotomyRequestForm( void );

	const std::string	getTarget( void ) const;
	void	execute(Bureaucrat const & executor) const throw( GradeTooLowException, NotSignedException );
private:
	const std::string	_target;
	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm & ref );
	RobotomyRequestForm & operator = ( RobotomyRequestForm & rhs );
};

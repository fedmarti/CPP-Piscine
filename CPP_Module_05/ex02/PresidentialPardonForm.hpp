/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/30 23:36:20 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( const std::string target );
	~PresidentialPardonForm( void );

	const std::string	getTarget( void ) const;
	void	execute(Bureaucrat const & executor) const throw( GradeTooLowException, NotSignedException );
private:
	const	std::string	_target;

	PresidentialPardonForm( void );
	PresidentialPardonForm & operator = (PresidentialPardonForm & );
	PresidentialPardonForm( PresidentialPardonForm & );
};
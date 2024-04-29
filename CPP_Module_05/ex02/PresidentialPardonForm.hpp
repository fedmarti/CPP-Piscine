/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/30 01:25:47 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( std::string name ) throw( GradeTooLowException, GradeTooHighException );
	~PresidentialPardonForm( void );

	void	execute(Bureaucrat const & executor) const;
private:
	PresidentialPardonForm( void );
	PresidentialPardonForm & operator = (PresidentialPardonForm & );
	PresidentialPardonForm( PresidentialPardonForm & );
};
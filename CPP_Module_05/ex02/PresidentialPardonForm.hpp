/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/28 19:38:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( std::string name, int e_grade, int s_grade ) throw( GradeTooLowException, GradeTooHighException );
	~PresidentialPardonForm( void );
private:
	PresidentialPardonForm( void );
	PresidentialPardonForm & operator = (PresidentialPardonForm & );
	PresidentialPardonForm( PresidentialPardonForm & );
};
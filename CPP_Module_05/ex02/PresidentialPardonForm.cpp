/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:58:16 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/28 18:59:27 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm("Presidential Pardon", 5, 25), _target(target)
{
    ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    ;
}

const std::string	PresidentialPardonForm::getTarget( void ) const
{
    return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const throw( GradeTooLowException, NotSignedException )
{
    if (executor.getGrade() > getExecutionGrade())
        throw(GradeTooLowException());
    if (!getSigned())
        throw(NotSignedException());
    std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("n\a", 0, 0)
{
    ;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm & rhs)
{
    (void)rhs;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm & ref ) : AForm("n\a", 0, 0)
{
    (void)ref;
}
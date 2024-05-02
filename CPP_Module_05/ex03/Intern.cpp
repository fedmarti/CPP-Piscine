/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:18:12 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern ( void )
{
    ;
}
Intern::~Intern ( void )
{
    ;
}
AForm *Intern::makeForm( std::string type, std::string target )
{

    for (std::string::iterator i = type.begin(); i != type.end(); i++)
        *i = tolower(*i);
    enum form_types type_num = Void_FT;
    
    for (int i = 0; i < Void_FT; i++)
    {
        if (type == AForm::FORM_TYPES[i])
        {
            type_num = static_cast<enum form_types>(i);
            break;
        }
    }
    
    switch (type_num)
    {
    case ShrubberyCreation:
        return (new ShrubberyCreationForm(target));
    case RobotomyRequest:
        return (new RobotomyRequestForm(target));
    case PresidentialPardon:
        return (new PresidentialPardonForm(target));
    default:
        break ;
    }
    std::cerr << "Form Type not matched" << std::endl;
    return (NULL);
}

Intern::Intern ( Intern &ref )
{
    (void)ref;
}
Intern & Intern::operator = ( Intern & rhs )
{
   (void)rhs;
   return (*this);
}


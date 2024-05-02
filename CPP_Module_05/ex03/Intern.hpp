/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:03:44 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/02 15:21:59 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern ( void );
    ~Intern ( void );
    AForm *makeForm( std::string type, std::string name );
private:
    Intern ( Intern & );
    Intern & operator = ( Intern & rhs );
};
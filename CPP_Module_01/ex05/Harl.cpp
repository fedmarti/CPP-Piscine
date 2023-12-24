/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:41 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 19:00:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void	Harl::debug ( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info ( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning ( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error ( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
	for (int i = 0; i < Null; i++)
	{
		if (Harl::COMPLAINTS[i] == level)
		{
			(this->*Harl::complaint[i])();
			return ;
		}
	}
}

Harl::Harl( void )
{
	this->complaint[Debug] = &Harl::debug;
	this->complaint[Info] =  &Harl::info;
	this->complaint[Warning] = &Harl::warning;
	this->complaint[Error] = &Harl::error;
}

Harl::~Harl( void )
{
	return ;
}

const std::string Harl::COMPLAINTS[Null] = {"Debug", "Info", "Warning", "Error"};
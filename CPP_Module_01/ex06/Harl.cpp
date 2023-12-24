/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:41 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 20:21:10 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void	Harl::debug ( void )
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info ( void )
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning ( void )
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error ( void )
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
	int lev = Null;


	for (int i = 0; i < Null; i++)
	{
		if (level == Harl::COMPLAINTS[i])
		{
			lev = i;
			break ;
		}
	}
	
	switch (lev)
	{
	case Debug:
		this->debug();
	case Info:
		this->info();
	case Warning:
		this->warning();
	case Error:
		this->error(); 
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
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

const std::string Harl::COMPLAINTS[Null] = {"DEBUG", "INFO", "WARNING", "ERROR"};
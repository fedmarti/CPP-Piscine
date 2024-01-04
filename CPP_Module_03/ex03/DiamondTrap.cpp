/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:23:00 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 01:07:27 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap("Void_clap_name"), FragTrap("Void_clap_name")
{
	this->_name = "Void";
}

DiamondTrap::DiamondTrap( std::string name ) : ScavTrap( name + "_clap_name"), FragTrap( name + "_clap_name"), _name(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap()
{
	this->_name = "Dvoid";
}
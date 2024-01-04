/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:25:23 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 21:49:05 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap clappy("clappy");
	DiamondTrap diamonz("Diamonz");

	clappy.attack("Diamonz");
	diamonz.takeDamage(clappy.getAttackDamage());
	diamonz.attack("Diamonz");
	clappy.takeDamage(diamonz.getAttackDamage());
	clappy.beRepaired(1);
	diamonz.whoAmI();
	diamonz.guardGate();
	diamonz.highFivesGuys();
}
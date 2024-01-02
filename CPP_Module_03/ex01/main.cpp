/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:25:23 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/03 00:41:08 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clappy("clappy");
	ScavTrap scavo("scavo");

	clappy.attack("scavo");
	scavo.takeDamage(clappy.getAttackDamage());
	scavo.attack("clappy");
	clappy.takeDamage(scavo.getAttackDamage());
	clappy.beRepaired(1);
	scavo.guardGate();
}
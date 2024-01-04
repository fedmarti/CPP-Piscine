/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:25:23 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/03 00:41:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clappy("clappy");
	// ScavTrap scavo("scavo");
	FragTrap fraggy("fraggy");

	clappy.attack("fraggy");
	fraggy.takeDamage(clappy.getAttackDamage());
	fraggy.attack("clappy");
	clappy.takeDamage(fraggy.getAttackDamage());
	clappy.beRepaired(1);
	fraggy.highFivesGuys();
}
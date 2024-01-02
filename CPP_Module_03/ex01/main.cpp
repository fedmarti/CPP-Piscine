/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:25:23 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/30 23:26:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clappy("clappy");
	clappy.attack("Nothing");
	clappy.takeDamage(7);
	clappy.beRepaired(1);
	clappy.takeDamage(7);
}
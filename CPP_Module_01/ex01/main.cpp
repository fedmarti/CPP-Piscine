/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:34 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 00:14:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main ( void )
{
	const int	horde_size = 5;
	Zombie		*dynamic = zombieHorde(horde_size, "Dynamic");
	
	for (int i = 0; i < horde_size; i++)
		dynamic[i].announce();
	delete [] dynamic;
}
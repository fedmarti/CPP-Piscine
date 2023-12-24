/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:34 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 23:37:33 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main ( void )
{
	Zombie *dynamic = newZombie("Dynamic");
	
	dynamic->announce();
	randomChump("bozo");
	delete(dynamic);
}
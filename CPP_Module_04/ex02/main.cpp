/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:53:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 13:09:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include <iostream>


int main()
{
	const int	len = 10;
	Animal 		*gang[len];

	for (int i = 0; i < (len / 2); i++)
		gang[i] = new Dog;
	for (int i = len / 2; i < len; i++)
		gang[i] = new Cat;

	for (int i = 0; i < len; i++)
	{
		std::cout << "Animal N." << i << " type: " << gang[i]->getType() << "\n";
		std::cout << "Brain address: " << gang[i]->getBrain() << std::endl;
	}
	for (int i = 0; i < len; i++)
		delete gang[i];
}
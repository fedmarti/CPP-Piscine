/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:53:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 02:32:04 by fedmarti         ###   ########.fr       */
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
	Animal		copyCat;
	Animal		copyDawg;

	for (int i = 0; i < (len / 2); i++)
		gang[i] = new Dog;
	for (int i = len / 2; i < len; i++)
		gang[i] = new Cat;

	for (int i = 0; i < len; i++)
	{
		std::cout << "Animal N." << i << " type: " << gang[i]->getType() << "\n";
		std::cout << "Brain address: " << gang[i]->getBrain() << std::endl;
	}
	copyDawg = *gang[len / 2 - 1];
	std::cout << "CopyDog brain: " << copyDawg.getBrain()<< "\n";
	copyCat = *gang[len - 1];
	std::cout << "CopyCat brain: " << copyCat.getBrain() << "\n"; 



	for (int i = 0; i < len; i++)
		delete gang[i];
}
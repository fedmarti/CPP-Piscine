/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:53:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 21:59:23 by fedmarti         ###   ########.fr       */
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
	Cat		copyCat;
	Dog		copyDawg;

	for (int i = 0; i < (len / 2); i++)
	{
		gang[i] = new Dog;
		Dog *tempdog = static_cast<Dog *>(gang[i]);
		std::cout << "Brain address: " << tempdog->getBrain() << std::endl;
	}
	for (int i = len / 2; i < len; i++)
	{
		gang[i] = new Cat;
		Cat *tempcat = static_cast<Cat *>(gang[i]);
		std::cout << "Brain address: " << tempcat->getBrain() << std::endl;
	}

	copyDawg = *static_cast<Dog *>(gang[len / 2 - 1]);
	std::cout << "CopyDog brain: " << copyDawg.getBrain()<< "\n:";
	copyCat = *static_cast<Cat *>(gang[len - 1]);
	std::cout << "CopyCat brain: " << copyCat.getBrain() << "\n"; 



	for (int i = 0; i < len; i++)
		delete gang[i];
}
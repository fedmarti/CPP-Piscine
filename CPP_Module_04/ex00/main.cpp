/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:18:26 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 13:22:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// int main()
// {
// 	const Animal *meta = new Animal();
// 	const Animal *Kitty = new Cat();
// 	const Animal *Dawg = new Dog();
	
// 	std::cout << Kitty->getType() << " " << std::endl;
// 	std::cout << Dawg->getType() << " " << std::endl;
// 	Kitty->makeSound();
// 	Dawg->makeSound();
// 	meta->makeSound();

// 	delete(meta);
// 	delete(Kitty);
// 	delete(Dawg);
// 	return (0);
// }

int main()
{
	Animal *meta = new Animal();
	Animal *Kitty = new Cat();
	Animal *Dawg = new Dog();
	Animal temp(*meta);


	*meta = *Dawg;
	*Dawg = *Kitty;
	*Kitty = temp;
	std::cout << "Kitty: " << Kitty->getType() << " " << std::endl;
	std::cout << "Dawg: " << Dawg->getType() << " " << std::endl;
	std::cout << "meta: " << meta->getType() << " " << std::endl;
	std::cout << "Kitty: ";
	Kitty->makeSound();
	std::cout << "Dawg: " ;
	Dawg->makeSound();
	std::cout << "meta: " ;
	meta->makeSound();

	delete(meta);
	delete(Kitty);
	delete(Dawg);
	return (0);
}
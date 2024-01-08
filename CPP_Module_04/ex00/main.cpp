/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:18:26 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 19:27:06 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *car = new Cat();
	const Animal *Dawg = new Dog();
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongKitty = new WrongCat();

	std::cout << car->getType() << " " << std::endl;
	std::cout << Dawg->getType() << " " << std::endl;
	std::cout << wrongKitty->getType() << " " << std::endl;
	std::cout << "Dog: ";
	car->makeSound();
	std::cout << "Car: ";
	Dawg->makeSound();
	std::cout << "Animal: ";
	meta->makeSound();
	std::cout << "WrongAnimal casted WrongCat: ";
	wrongKitty->makeSound();
	std::cout << "WrongAnimal: ";
	wrongMeta->makeSound();
	std::cout << "WrongCat casted WrongCat: ";
	static_cast<const WrongCat *>(wrongKitty)->makeSound();
	delete(meta);
	delete(car);
	delete(Dawg);
	delete(wrongKitty);
	delete(wrongMeta);
	std::cout << "\e[1;30m Do not the cat! \e[0m" << std::endl;
	return (0);
}

// int main()
// {
// 	Animal *meta = new Animal();
// 	Animal *Kitty = new Cat();
// 	Animal *Dawg = new Dog();
// 	Animal temp(*meta);


// 	*meta = *Dawg;
// 	*Dawg = *Kitty;
// 	*Kitty = temp;
// 	std::cout << "Kitty: " << Kitty->getType() << " " << std::endl;
// 	std::cout << "Dawg: " << Dawg->getType() << " " << std::endl;
// 	std::cout << "meta: " << meta->getType() << " " << std::endl;
// 	std::cout << "Kitty: ";
// 	Kitty->makeSound();
// 	std::cout << "Dawg: " ;
// 	Dawg->makeSound();
// 	std::cout << "meta: " ;
// 	meta->makeSound();

// 	delete(meta);
// 	delete(Kitty);
// 	delete(Dawg);
// 	return (0);
// }
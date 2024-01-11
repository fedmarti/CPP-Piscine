/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:53:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 22:08:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include <iostream>


int main()
{
	Dog dog;
	// Animal animal
	Animal *car = new Cat();
	// animal.makeSound;
	dog.makeSound();
	car->makeSound();
	delete car;
}
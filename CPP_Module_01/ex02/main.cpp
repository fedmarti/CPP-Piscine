/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:21:07 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 00:39:33 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main ( void )
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "brain addr: " << &brain << std::endl;
	std::cout << "ptr stored addr: " << stringPTR << std::endl;
	std::cout << "ref stored addr: " << &stringREF << std::endl;

	std::cout << "brain: " << brain << std::endl;
	std::cout << "ptr: " << *stringPTR << std::endl;
	std::cout << "reg: " << stringREF << std::endl;
}
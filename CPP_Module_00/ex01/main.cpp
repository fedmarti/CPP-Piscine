/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:31:42 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 20:05:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
	Phonebook 	pb("Awesome");
	std::string	prompt;
	do
	{
		std::cout << "SEARCH, ADD OR EXIT?\n";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			pb.add();
		else if (prompt == "SEARCH")
			pb.search();
		else if (prompt == "EXIT" || std::cin.fail())
			break ;
		prompt = "";
	} while (1);
}

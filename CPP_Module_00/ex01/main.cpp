/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:31:42 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/20 01:21:07 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
//#include <phonebook.h>

int main()
{
	Contact contact;

	if (!contact.is_valid())
		std::cout<<"in";
	std::cout<<"vaild contact\n";
}

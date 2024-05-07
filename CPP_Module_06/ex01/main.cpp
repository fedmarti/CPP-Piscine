/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:56:48 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/07 20:00:08 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	try
	{
		Data b("Test", 1);

		std::cout << b;

		uintptr_t p = Serializer::serialize(&b);

		Data *test_ptr = Serializer::deserialize(p);

		std::cout << *test_ptr;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what();
	}
}
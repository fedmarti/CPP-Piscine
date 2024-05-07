/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:49:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/07 22:18:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>

using std::exception;

Base *generate( void )
{
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	default:
		break;
	}
	return (NULL);
}

void identify(Base *p)
{
	std::cout << "pointer is of type: ";
	
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}

	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}

 	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	
	std::cout << "Unknown";
}

void identify(Base &p)
{
	std::cout << "pointer is of type: ";
	try
	{
		A &ptr = dynamic_cast<A&>(p);
		(void)ptr;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (exception &e)
	{
		(void)e;
	}

	try
	{
		B &ptr = dynamic_cast<B&>(p);
		(void)ptr;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (exception &e)
	{
		(void)e;
	}

	try
	{
		C &ptr = dynamic_cast<C&>(p);
		(void)ptr;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (exception &e)
	{
		(void)e;
	}

	std::cout << "Unknown";
}

int main()
{
	Base *p = generate();

	if (!p)
		return (1);

	identify(p);
	identify(*p);
	delete p;

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:55:14 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/19 23:06:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	for (int i = 1; i < argc; i++)
	{
		for (int r = 0; argv[i][r]; r++)
		{
			if (argv[i][r] >= 'a' && argv[i][r] <= 'z')
				std::cout<<(char)(argv[i][r] - ('a' - 'A'));
			else
				std::cout<<argv[i][r];
		}
	}
	std::cout<<std::endl;
}

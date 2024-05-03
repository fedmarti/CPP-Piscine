/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:57:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/03 17:34:35 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm("Shrubbery Creation", 137, 145), _target(target)
{
	;
}

const std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (_target);
}

/*
..##..
.####.
######
..##



.#
###
.#

...#..
..###.
.#####
#######
...#...
*/


void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw( GradeTooLowException, NotSignedException )
{
	if (!getSigned())
		throw ( NotSignedException() );
	if (executor.getGrade() > getExecutionGrade())
		throw( GradeTooLowException() );
	
	std::ofstream file;
	file.open((std::string(getTarget() + "_shrubbery").c_str()), std::ios_base::app);
	
	srand(time(NULL));
	int height = rand() % 5 + 3;
	int width = height + 2;
	
	file << "\n";
	for (int i = 0; i < height - 1; i++)
	{
		file << std::string((width / 2 - i), ' ') << std::string(1 + i * 2 + (width % 2 == 0), '#');
		file << "\n";
	}
	// file << std::string(width + (width % 2 == 0), '#') << '\n';
	file << std::string(width / 2, ' ') + std::string((width % 2 == 0) + 1, '#') << '\n';
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("n\a", 0, 0)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm & ref ) : AForm("n\a", 0, 0)
{
	(void)ref;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = ( ShrubberyCreationForm & rhs )
{
	(void)rhs;
	return (*this);
}
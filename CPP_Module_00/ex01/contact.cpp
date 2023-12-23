/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:14:05 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/20 01:17:53 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

static bool	enter_field(std::string field_name, std::string field)
{
	std::cout<<field_name<<std::endl;
	std::cin>>field;
	if (field == "")
	{
		std::cout<<field_name<<" field can't be blank\n";
		return false;
	}
	if (field_name == "Number")
	{
		if (field.size() != 10)
		{		
			std::cout<<field_name<<" must be 10 characters long\n";
			return (false);
		}
		for (std::string::const_iterator i = field.begin(); i != field.end(); i++)
		{
			if (!std::isdigit(*i))
			{
				std::cout<<field_name<<" must be a number\n";
				return (false);
			}
		}
	}
	return (true);
}

Contact::Contact()
{
	this->valid = false;
	if (!enter_field("First Name", this->first_name))
		return ;
	if (!enter_field("Last Name", this->last_name))
		return ;
	if (!enter_field("Nickname", this->nickname))
		return ;
	if (!enter_field("Number", this->number))
		return ;
	if (!enter_field("Darkest Secret", this->secret))
		return ;
	this->valid = true;	
	return ;
}	

Contact::~Contact()
{
	return ;
}

bool Contact::is_valid()
{
	return this->valid;
}



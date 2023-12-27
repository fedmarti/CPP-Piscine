/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:10:23 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 20:05:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

static bool	enter_field(std::string field_name, std::string &field)
{
	std::cout << field_name << std::endl;
	std::getline(std::cin, field);
	if (field == "")
	{
		std::cout << field_name << " field can't be blank\n";
		return false;
	}
	if (field_name == Contact::FIELD_NAMES[Number])
	{
		if (field.size() != 10)
		{		
			std::cout << field_name << " must be 10 characters long\n";
			return (false);
		}
		for (std::string::const_iterator i = field.begin(); i != field.end(); i++)
		{
			if (!std::isdigit(*i))
			{
				std::cout << field_name << " must be a number\n";
				return (false);
			}
		}
	}
	return (true);
}

void	Phonebook::add( void )
{
	std::string field[Null];

	for (int i = 0; i != Null; i++)
		if (!enter_field(Contact::FIELD_NAMES[i], field[i])) {return ;}
	this->_lastAdded = (this->_lastAdded + 1) % Phonebook::MAX_CONTACTS;
	this->_nContacts += this->_nContacts < Phonebook::MAX_CONTACTS;
	this->_contacts[this->_lastAdded].fill(field[0], field[1], field[2], field[3], field[4]);
}

void	Phonebook::_displayColumn(std::string content)
{
	std::cout.setf(std::ios::right);
	std::cout << "|";
	if (content.length() > Phonebook::DISPLAY_WIDTH)
		std::cout << content.substr(0, Phonebook::DISPLAY_WIDTH - 1) + '.';
	else
		std::cout << std::setw(Phonebook::DISPLAY_WIDTH) << content;
}

void	Phonebook::_displayAll() const
{
	// Phonebook::_displayColumn(std::string('-', Phonebook::DISPLAY_WIDTH));
	_displayColumn("F. Name");
	_displayColumn("L. Name");
	_displayColumn("Nickname");
	_displayColumn("Number");
	std::cout << "|";
	std::cout << std::endl;
	for (int i = 0; i < this->_nContacts; i++)
	{
		_displayColumn(this->_contacts[i].getFirstName());
		_displayColumn(this->_contacts[i].getLastName());
		_displayColumn(this->_contacts[i].getNickname());
		_displayColumn(this->_contacts[i].getNumber());
		std::cout << "|" << std::endl;
	}
}

void	Phonebook::search( void ) const
{
	if (this->_nContacts == 0)
	{
		_displayColumn("you");
		_displayColumn("have");
		_displayColumn("no");
		_displayColumn("bitches");
		std::cout << "|" << std::endl;
		return ;
	}
	this->_displayAll();
	std::string input;
	std::cout << "Who are you interested in?\n";
	std::getline(std::cin, input);
	int index = atoi(input.c_str());
	if (index >= Phonebook::MAX_CONTACTS)
	{
		std::cout << "Number too big!\nGive n(0-" << Phonebook::MAX_CONTACTS << ")\n";
		return ;
	}
	else if (index < 0)
	{
		std::cout << "Number too small?\nSeriously, why did you type a negative?\n";
		return ;
	}
	else if (index >= _nContacts)
	{
		std::cout << "Empty contact\n";
		return ;
	}
	std::cout << "First Name:\n" << this->_contacts[index].getFirstName();
	std::cout << "\nLast Name:\n" << this->_contacts[index].getLastName();
	std::cout << "\nNickname:\n" << this->_contacts[index].getNickname();
	std::cout << "\nNumber:\n" << this->_contacts[index].getNumber();
	std::cout << "\nDeepest secret:\n" << this->_contacts[index].getSecret() << std::endl;
}

Phonebook::Phonebook( void )
{
	this->_PhoneBookName = "boring";
	this->_nContacts = 0;
	this->_lastAdded = -1;
}

Phonebook::~Phonebook( void )
{
	return ;
}

Phonebook::Phonebook( std::string name ) : _PhoneBookName(name)
{
	this->_nContacts = 0;
	this->_lastAdded = -1;
	if (name == "Epic")
		this->_contacts[0].fill("ur", "mom", "urmom", "69", "i hav sex wth her B)");
}


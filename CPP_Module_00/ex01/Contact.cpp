/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:14:05 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 20:05:03 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName( void ) const
{
	return this->_first_name;
}

std::string Contact::getLastName( void ) const
{
	return this->_last_name;
}

std::string Contact::getNickname ( void ) const
{
	return this->_nickname;
}

std::string Contact::getNumber ( void ) const
{
	return this->_number;
}

std::string Contact::getSecret ( void ) const
{
	return this->_secret;
}

void Contact::fill( std::string name, std::string surname, std::string nick, std::string nb, std::string scrt )
{
	this->_first_name = name;
	this->_last_name = surname;
	this-> _nickname = nick;
	this->_number = nb;
	this->_secret = scrt;
	return ;
}	

Contact::Contact( void )
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::FIELD_NAMES[] = {"First Name", "Last Name", "Nickname", "Number", "Deepest Secret"};
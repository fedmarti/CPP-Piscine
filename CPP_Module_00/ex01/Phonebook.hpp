/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:58:11 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 20:05:11 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class Phonebook 
{
	public:
		Phonebook ( std::string );
		Phonebook ( void );
		~Phonebook ( void );
		void	add ( void );
		void	search ( void ) const;
		static const int	MAX_CONTACTS = 8;
	private:
		static const int	DISPLAY_WIDTH = 10;
		std::string	_PhoneBookName;
		Contact 	_contacts[MAX_CONTACTS];
		int			_nContacts;
		int			_lastAdded;
		static void _displayColumn ( std::string );
		void		_displayAll ( void ) const;
		void		_displaySingle ( int index ) const;
		
};
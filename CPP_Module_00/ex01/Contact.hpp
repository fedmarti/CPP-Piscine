/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:42:48 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/23 14:53:27 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
	public:
		static std::string FIELD_NAMES[];

		Contact ( void );
		~Contact ( void );
		
		std::string getFirstName ( void ) const;
		std::string getLastName ( void ) const;
		std::string getNickname ( void ) const;
		std::string getNumber ( void ) const;
		std::string getSecret ( void ) const;
		
		void	fill( std::string name, std::string surname, std::string nick, std::string nb, std::string scrt );
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _number;
		std::string _secret;		
};

enum field_names {
	FirstName,
	LastName, 
	Nickname, 
	Number, 
	DeepestSecret,
	Null
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:42:48 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/20 01:10:43 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
	public:
		Contact ();
		~Contact ();
		bool	is_valid();
	private:
		bool		valid;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;		
};

#endif

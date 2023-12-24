/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:53:56 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 01:15:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
	private:
	
		std::string _type;
	public:

		std::string getType( void ) const;
		void		setType( std::string );
		Weapon( std::string );
		Weapon( void );
		~Weapon( void );
};

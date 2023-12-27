/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:53:56 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/27 23:31:20 by fedmarti         ###   ########.fr       */
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
		void		setType( void * );
		Weapon( std::string );
		Weapon( void * );
		Weapon( void );
		~Weapon( void );
};

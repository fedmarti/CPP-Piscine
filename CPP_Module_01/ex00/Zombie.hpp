/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 00:18:11 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie {

	private:
		std::string _name;
	public:
		void	announce ( void ) const;
		
		Zombie( std::string name );
		Zombie( void );
		~Zombie( void );
};
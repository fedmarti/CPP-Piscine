/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:02:01 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/30 18:59:37 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		void	attack( void ) const;
		HumanA( std::string, Weapon & );
		HumanA(void *, Weapon &);
		~HumanA( void );
};
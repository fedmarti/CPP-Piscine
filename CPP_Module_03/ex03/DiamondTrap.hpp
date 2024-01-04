/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:23:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 22:48:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
private:
	std::string _name;
	DiamondTrap( void );
	DiamondTrap( DiamondTrap & );
	DiamondTrap & operator=( DiamondTrap & );
	void 		_printName( void ) const;
public:
	
	using	ScavTrap::attack;
	using	FragTrap::takeDamage;
	DiamondTrap( std::string );
	~DiamondTrap( void );
	void	whoAmI( void );
};
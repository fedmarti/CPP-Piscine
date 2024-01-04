/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:54:44 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 22:12:06 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

enum e_modes {
	Default,
	GateKeeper
};

class ScavTrap : virtual public ClapTrap
{
private:
	void	_printName( void ) const;
	enum e_modes _mode;
public:
	ScavTrap( ScavTrap & );
	ScavTrap( std::string name );
	ScavTrap( void );
	~ScavTrap( void );

	void	attack( std::string target ) const;
	void	guardGate( void );
	ScavTrap & operator=( ScavTrap & );
};

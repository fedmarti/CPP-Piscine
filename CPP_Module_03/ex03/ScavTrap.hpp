/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:54:44 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/03 22:29:23 by fedmarti         ###   ########.fr       */
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

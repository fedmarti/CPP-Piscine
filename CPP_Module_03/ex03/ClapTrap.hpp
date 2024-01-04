/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:35:08 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 23:47:31 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap
{
public:
	ClapTrap( std::string );
	~ClapTrap( void );

	void	attack( const std::string & target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	int		getHitPoints( void ) const;
	int		getEnergyPoints( void ) const;
	int		getAttackDamage ( void ) const;
	std::string	getName( void ) const;

	ClapTrap & operator=( ClapTrap & );
	ClapTrap( ClapTrap & );

private:
	std::string _name;
	void _printName( void ) const;
protected:
	ClapTrap( void );
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};
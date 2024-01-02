/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:35:08 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/02 23:18:15 by fedmarti         ###   ########.fr       */
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
	ClapTrap( void );
	ClapTrap( ClapTrap & );

private:
	std::string _name;
protected:
	void _printName( void ) const;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	std::string _type;

};
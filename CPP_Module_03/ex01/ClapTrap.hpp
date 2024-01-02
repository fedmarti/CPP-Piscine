/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:35:08 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/01 00:08:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap
{
public:
	ClapTrap( std::string );
	~ClapTrap( void );

	void	attack( const std::string & target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	ClapTrap & operator=( ClapTrap & );
	ClapTrap( void );
	ClapTrap( ClapTrap & );
private:
	void printName( void ) const;
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	std::string _type;
};
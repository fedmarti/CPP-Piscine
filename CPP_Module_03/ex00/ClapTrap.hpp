/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:35:08 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/31 00:20:25 by fedmarti         ###   ########.fr       */
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
private:
	ClapTrap( ClapTrap & );
	ClapTrap( void );
	void printName( void ) const;
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
protected:
	std::string _type;
};
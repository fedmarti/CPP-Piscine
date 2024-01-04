/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:23:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 01:08:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
private:
	std::string _name;
	
public:
	
	DiamondTrap( void );
	DiamondTrap( std::string );
	DiamondTrap( DiamondTrap & );
	~DiamondTrap( void );
	void	whoAmI( void );
	
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:54:44 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/01 00:09:12 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap( void ): ClapTrap();
		ScavTrap( std::string ): ClapTrap( std::string );
	public:
	;


	~ScavTrap();
};


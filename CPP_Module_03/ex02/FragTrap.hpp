/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:50:31 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/03 00:40:26 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap( std::string );
	FragTrap( FragTrap & );
	~FragTrap( void );
	void highFivesGuys( void ) const;
};
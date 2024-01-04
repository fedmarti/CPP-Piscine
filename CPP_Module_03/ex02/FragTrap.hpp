/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:50:31 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 23:44:40 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap( std::string );
	FragTrap( FragTrap & );
	~FragTrap( void );

	FragTrap & operator=( FragTrap & );
	void highFivesGuys( void ) const;
};
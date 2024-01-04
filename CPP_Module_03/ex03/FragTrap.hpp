/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:50:31 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 22:35:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
	void	_printName( void ) const;
protected:
	~FragTrap( void );
	FragTrap( void );
	FragTrap( FragTrap & );
public:
	FragTrap( std::string );

	FragTrap & operator=( FragTrap & );
	void highFivesGuys( void ) const;
};
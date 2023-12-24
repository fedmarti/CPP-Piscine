/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:43 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 18:49:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum complaints {
	Debug,
	Info,
	Warning,
	Error,
	Null
};

class Harl {
	private:
		const static std::string COMPLAINTS[Null];
		void (Harl::*complaint[Null])( void );
		void	debug ( void );
		void	info ( void );
		void	warning ( void );
		void	error ( void );
	public:
		void complain( std::string level );
		Harl( void );
		~Harl ( void );
};

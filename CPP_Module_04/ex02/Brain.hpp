/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:41:56 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/06 20:45:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain {
public:
	Brain( void );
	Brain( Brain & );
	~Brain( void );

	Brain & operator=( Brain & );
private:
	static const int NIDEAS = 100;
	std::string _ideas[NIDEAS];
};
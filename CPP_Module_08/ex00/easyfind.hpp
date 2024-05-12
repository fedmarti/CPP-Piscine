/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:15:14 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/12 00:41:14 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

template <typename T>
typename T::iterator	easyfind(T& container, int val) throw(std::exception)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (static_cast<int>(*it) == val)
			return (it);
	}
	throw(std::exception()); 
}

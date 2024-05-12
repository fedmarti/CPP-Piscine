/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:15:14 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/12 16:28:53 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int val) throw(std::exception)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (static_cast<int>(*it) == val)
		return (it);
		
	throw(std::exception()); 
}

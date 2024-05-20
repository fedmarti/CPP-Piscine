/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:15:14 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/20 18:39:10 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);


	// if (it == container.end())
		// throw(std::exception()); 
	return (it);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:55:12 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/09 13:06:53 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void	iter(T *arr, int len, void foo(T))
{
	for (int i = 0; i < len; i++)
	{
		foo(arr[i]);
	}
}

template <typename T>
void	print(T thing)
{
	std::cout << thing << std::endl;
}
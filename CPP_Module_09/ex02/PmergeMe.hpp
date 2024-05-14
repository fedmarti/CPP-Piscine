/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:57:36 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/14 23:58:35 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe &);
	PmergeMe & operator = ( PmergeMe & );
	~PmergeMe();
private:

};
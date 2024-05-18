/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:57:36 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/18 04:54:31 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>
#include <utility>


using	std::deque;
using	std::vector;
using	std::pair;

typedef pair<int[2], bool> couple; 


class PmergeMe
{
public:
	//sorts using the ford-jonson algorithm, and return the time elapsed in us
	static long	mergesort( deque<int> &seq );
	static long	mergesort( vector<int> &seq );

private:

	// static void	swap_sequences( T seq, uint subseq_a) throw (std::exception);
	static void	_update_indexes(struct subsequence &sub, int offset);
	PmergeMe( PmergeMe & );
	PmergeMe & operator = ( PmergeMe & );
	~PmergeMe();
	PmergeMe();
};

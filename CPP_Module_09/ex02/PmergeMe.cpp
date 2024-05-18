/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:56:16 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/18 06:16:07 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <algorithm>
#include <exception>
#include <cmath>
#include <iostream>
using std::clock_t;
using std::clock;

/*
static void	__print(int n)
{
	std::cout << n << " ";
}

static void	__print(couple p)
{
	__print(p.first[0]);
	if (p.second)
		__print(p.first[1]);
}

template <typename T, typename U>
static void _print(T thing, void (gen_print)(U))
{
	std::for_each(thing.begin(), thing.end(), gen_print);
	std::cout << std::endl;
}
*/


PmergeMe::PmergeMe()
{
	;
}

PmergeMe::PmergeMe( PmergeMe & )
{
	;
}

template <typename T>
inline bool is_sorted( T vec )
{
	for (typename T::iterator it = vec.begin(); it < vec.end() - 1; it++)
		if (*it > *(it + 1)) {return false;}
	return (true);
}

template <typename T, typename Tp>
Tp section(T sequence)
{
	Tp child;

	for (typename T::iterator it = sequence.begin(); it < sequence.end(); it += 2)
	{
		pair<int[2], bool> new_pair;
		new_pair.first[0] = *it;
		new_pair.first[1] = *it;
		new_pair.second = false;
		if (it + 1 != sequence.end())
		{
			new_pair.first[1] = *(it + 1);
			new_pair.second = true;
		}
		child.push_back(new_pair);
	}
	return (child);
}

template <typename T, typename Tp>
T couples_to_sequence(Tp sequence)
{
	T child;

	for(typename Tp::iterator it = sequence.begin(); it < sequence.end(); it++)
		child.push_back((*it).first[0]);
	return (child);
}

template <typename T, typename Tp>
T expand ( Tp vec )
{
	T expanded;

	for (typename T::iterator it = vec.begin(); it < vec.end(); it++)
	{
		int val = (*it).first;
		expanded.push_back(val);
		if ((*it).second.second)
		{
			val = (*it).second.first;
			expanded.push_back(val);
		}
	}
	return (expanded);
}

//T is a sequenced container of int
//Tp is the same kind of container, but of type pair<int[2], bool> template <typename T>
template <typename T, typename Tp> 
T ford_johnson( T &vec )
{
	if (is_sorted(vec))
		return (vec);
	
	//creates pairs and swaps them if out of order
	Tp couples = section<T, Tp>(vec);

	for (typename Tp::iterator it = couples.begin(); it < couples.end(); it++)
	{
		if ((*it).second && (*it).first[0] < (*it).first[1])
			std::swap((*it).first[0] , (*it).first[1]);
	}

	//creates a sorted sequence out of the biggest of each couple 
	T expanded = couples_to_sequence<T, Tp>(couples);
	T sorted_sequence = static_cast<T>(ford_johnson<T, Tp>(expanded));
	
	//adds the smallest of each couple back to the sequence, in order, using biSec
	for (typename Tp::iterator it = couples.begin(); it < couples.end(); it++)
	{
		if (!(*it).second)
			continue ;
		
		int big = (*it).first[0], small = (*it).first[1];
		(void)big;
		typename T::iterator ub = std::upper_bound(sorted_sequence.begin(), sorted_sequence.end(), small);
		sorted_sequence.insert(ub, small);
	}
	return (sorted_sequence);
}

long PmergeMe::mergesort( vector<int> &sequence )
{
	const std::clock_t	start = clock();

	sequence = ford_johnson<vector<int>, vector<couple> >(sequence);

	return static_cast<long>(clock() - start);
}

long	PmergeMe::mergesort( deque<int> &seq )
{
	const std::clock_t	start = clock();

	seq = ford_johnson<deque<int>, deque<couple> >(seq);
	return static_cast<long>(clock() - start);
}


PmergeMe::~PmergeMe()
{
	;
}

PmergeMe & PmergeMe::operator= ( PmergeMe & )
{
	return (*this);
}

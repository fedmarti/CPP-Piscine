/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:14:14 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/13 19:42:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	MutantStack() : std::stack<T>() { ;};
	MutantStack( MutantStack & ref ) : std::stack<T>(ref) { ;};
	~MutantStack(){ ;};
	
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {return (this->c.begin());};
	iterator end() {return (this->c.end());};
};

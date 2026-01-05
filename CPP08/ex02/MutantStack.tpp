/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:24 by lparolis          #+#    #+#             */
/*   Updated: 2026/01/05 22:38:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	DBG_MSG("MutantStack constructor called");
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
	DBG_MSG("MutantStack copy constructor called");
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	DBG_MSG("MutantStack copy operator called");
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	DBG_MSG("MutantStack destructor called");
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() const
{
	return this->c.end();
}
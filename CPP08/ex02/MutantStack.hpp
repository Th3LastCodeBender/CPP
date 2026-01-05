/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:26:18 by lparolis          #+#    #+#             */
/*   Updated: 2026/01/05 22:38:26 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define 	MUTANTSTACK_HPP

#include "eader.h"

template<typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typename std::stack<T>::container_type::iterator begin();
		typename std::stack<T>::container_type::iterator end();

		typename std::stack<T>::container_type::iterator begin() const;
		typename std::stack<T>::container_type::iterator end() const;
};


#endif

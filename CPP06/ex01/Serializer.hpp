/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:04:15 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 16:02:52 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

#ifndef Serializer_HPP
#define Serializer_HPP

#define uintptr_t unsigned long

struct Data;

class Serializer
{
	private:

		Serializer();

	public:

		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

struct Data
{
	std::string content;
	int			id; 
};

#endif // Serializer_HPP
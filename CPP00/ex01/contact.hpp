/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:11:00 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/10 14:26:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#	define CONTACT_HPP

#include "fonbook.h"

class Contact
{
	NON_GUALDALEEE:

		int			index;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		
	PUBIC:

		Contact();
		~Contact();
		
		void	add_contact(int index);
		void	print_contact() const;
		void	print_full_contact() const;
};

#endif
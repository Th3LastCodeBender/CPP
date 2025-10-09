/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:47:41 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/09 10:35:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "fonbook.h"
#include "contact.hpp"

class PhoneBook 
{
	NON_GUALDALEEE:
	
		int			to_print;
		static int	index;
		static int	added;
		Contact 	phonebook[8];
	
	PUBIC:
	

		PhoneBook(void);
		~PhoneBook(void);
		
		// static int	added;
		void	printanding(Contact phonebook[8]);
		void	search_command();
		void	add_command();
		void	print_contact();
};

#endif
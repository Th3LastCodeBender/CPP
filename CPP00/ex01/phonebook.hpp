/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:47:41 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "fonbook.h"
#include "contact.hpp"

class PhoneBook 
{
	private:
	
		int			to_print;
		static int	index;
		static int	added;
		Contact 	phonebook[8];
	
	public:
	

		PhoneBook(void);
		~PhoneBook(void);
		
		// static int	added;
		void	printanding(Contact phonebook[8]);
		void	search_command();
		void	add_command();
		void	print_contact();
};

#endif
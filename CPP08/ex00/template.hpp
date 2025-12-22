/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/22 15:56:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

class ValueNotFoundException : public std::exception
{
	private:
		std::string _msg;
	public:
		ValueNotFoundException(std::string msg) : _msg(msg) {};
		virtual const char *what() const throw() {return (_msg.c_str());}
		~ValueNotFoundException() throw() {};
};

template<typename T> void easyFind(T &vector, int value)
{
	std::vector<int>::iterator it;

	it = std::find(vector.begin(), vector.end(), value);
	
	if (it == vector.end())
		throw ValueNotFoundException("Value not found in the searched stack!\n");
	else
		std::cout << "Found at position: " << std::distance(vector.begin(), it) << std::endl;
}

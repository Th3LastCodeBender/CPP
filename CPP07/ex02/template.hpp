/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:23:07 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 15:18:07 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define 	TEMPLATE_HPP

#include "eader.h"

template<typename T>
class Array
{
	private:
	
		T		*_array;
		size_t _size;
		
	public:

		class IndexOutOfBoundException : public std::exception
		{
			private:
				std::string _msg;
			public:
				IndexOutOfBoundException() : _msg("Index out of bounds!") {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~IndexOutOfBoundException() throw() {};
		};

		Array()
		{
			DBG_MSG("Array constructor called!");
			this->_array = NULL;
			this->_size = 0;
		}

		Array(unsigned int size)
		{
			DBG_MSG("Array constructor called!");
			this->_size = size;
			this->_array = new T[size];
		}

		Array(const Array &obj) : _array(NULL), _size(obj._size)
		{
			DBG_MSG("Copy constructor called!");

			if (this->_size > 0)
			{
				this->_array = new T[this->_size];
			}
			
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_array[i] = obj._array[i];
			}
		}

		Array &operator=(const Array &obj) 
		{
			DBG_MSG("Array copy operator called!");
			
			if(this == &obj)
				return (*this);
			
			this->_size = obj._size;
			delete[] this->_array;

			this->_array = NULL;
			if (this->_size > 0)
			{
				this->_array = new T[this->_size];
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_array[i] = obj._array[i];
				}
					
			}
			return (*this);				
		}

		~Array()
		{
			DBG_MSG("Array destructor called!");
			
			delete[] this->_array;
		}

		size_t size() const {return (this->_size);}

		T &operator[](size_t index) const
		{
			if (index >= this->_size)
				throw IndexOutOfBoundException();
			else
				return (this->_array[index]);
		}
};


#endif

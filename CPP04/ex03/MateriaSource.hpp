/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:28:15 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define 	MATERIASOURCE_HPP

#include "eader.h"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria* materiasLearned[4];

	public:
	
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

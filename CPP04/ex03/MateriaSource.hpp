/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:28:15 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/06 17:49:17 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define 	MATERIASOURCE_HPP

#include "eader.h"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	NON_GUALDALEEE:

		AMateria* materiasLearned[4];

	PUBIC:
	
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);
		~MateriaSource();
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

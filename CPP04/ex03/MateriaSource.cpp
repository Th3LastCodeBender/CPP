/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/06 17:56:54 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	DBG_MSG("MateriaSource constructor called");
	for (size_t i = 0; i < 4; i++)
		materiasLearned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	DBG_MSG("MateriaSource copy contructor called");
	for (size_t i = 0; i < 4; i++)
		this->materiasLearned[i] = obj.materiasLearned[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	DBG_MSG("MateriaSource copy operator called");
	for (size_t i = 0; i < 4; i++)
		this->materiasLearned[i] = obj.materiasLearned[i]->clone();
}

MateriaSource::~MateriaSource()
{
	DBG_MSG("MateriaSource destructor called");
	delete[] this->materiasLearned;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Dude, what are you doing? Drugs!?" << std::endl;
		return;
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->materiasLearned[i])
		{
			DBUG_MSG("AMateria equipped in slot: ");
			std::cout << i << std::endl;
			this->materiasLearned[i] = m;
			return;
		}
	}
	
	DBUG_MSG("No more materias to learn!");
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 4; i > 0; i++)
	{
		if (this->materiasLearned[i] && this->materiasLearned[i]->getType().compare(type))
		{
			return (this->materiasLearned[i]);
		}
	}
	
	std::cout << "Well well well... looks like someone forgot what to remember!" << std::endl;
}

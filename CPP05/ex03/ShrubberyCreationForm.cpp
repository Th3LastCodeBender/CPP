/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:21 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:11:16 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	DBG_MSG("ShrubberyCreationForm constructor called!");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj.getTarget())
{
	DBG_MSG("ShrubberyCreationForm constructor created!");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    DBG_MSG("ShrubberyCreationForm copy operator called!");
	(void)obj;	
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	DBG_MSG("ShrubberyCreationForm destructor called!");
}

const std::string	ShrubberyCreationForm::getTarget()const
{
	return (this->_target);
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string name = getTarget() + "_shrubbery.txt";
	
	std::ifstream file_check(name.c_str());
    if (file_check.is_open())
	{
		throw FileNotCreated("BELIN! The file esiste già!");
		return ;
	}

	std::ofstream output_file(name.c_str());
    if (!output_file)
	{
		throw FileNotCreated("BELIN! file call failed!");
		return ;
	}

    output_file << "   /\\\n";
    output_file << "  /**\\\n";
    output_file << " /****\\\n";
    output_file << "/******\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << " /*||*\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
	output_file << std::endl;
	output_file << std::endl;
    output_file << "   /\\\n";
    output_file << "  /**\\\n";
    output_file << " /****\\\n";
    output_file << "/******\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << " /*||*\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
	output_file << std::endl;
	output_file << std::endl;
    output_file << "   /\\\n";
    output_file << "  /**\\\n";
    output_file << " /****\\\n";
    output_file << "/******\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << " /*||*\\\n";
    output_file << "   ||\n";
    output_file << "  /||\\\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
    output_file << "   ||\n";
}
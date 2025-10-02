/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:20:51 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parsing(int argc, char **argv)
{	
	if (argc < 4)
	{
		std::cout << "Alua, la finimmu? La roba va passata" << std::endl;
		return (0);
	}
	else if (argv[1] == NULL || argv[1][0] == ' ' || argv[1][0] == '\0')
	{
		std::cout << "Cosa devo leggere secondo te? I tarocchi? Belin che affare, passa un po il file di input invece di comportarti come un bambino con l'autismo" << std::endl;
		return (0);
	}
	else if (!file_parsing(argv[1]))
		return (0);
	else if (argv[2] == NULL || argv[2] == '\0' || argv[3] == NULL || argv[3] == '\0')
	{
		std::cout << "Belin figgeu, ogni minuto che passa diventi esponenzialmente piu' simpatico" << std::endl;
		return (0);
	}
	return (1);
}

int	file_parsing(std::string filename)
{
	std::fstream input_file(filename.c_str());
	
	if (!input_file.is_open())
	{
		std::cout << "Qualunque cacata tu mi abbia passato non e' roba buona, passiamo alla roba seria su, semmo chi mica pe gratta u cu a-e mosche" << std::endl;
		return (0);
	}

	std::string line;
	
	std::getline(input_file, line);
	if (line.empty())
	{
		std::cout << "ALÒOOA, FÉMMO I SERI, PER PIASÈ?" << std::endl;
		return (0);
	}
	input_file.close();
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:27:14 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 18:27:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main ( int argc, char **argv )
{
	std::string s1;
	std::string s2;
	
	if (parsing(argc, argv) == false)
		return (0);
	search_and_destroy(argv);
}

void	search_and_destroy(char **argv)
{
	std::stringstream 	buffer;
	std::fstream 		input_file(argv[1]);
	std::string 		file_content;
	std::string			to_find;
	std::string			to_replace;
	std::string			new_content;
	std::size_t			index;
	std::size_t			last;
	
	last = 0;
	index = 0;
	to_find = argv[2];
	to_replace = argv[3];
	buffer << input_file.rdbuf();
	file_content = buffer.str();

	index = (file_content.find(to_find, index));
	while (index != std::string::npos) 
	{
		new_content += file_content.substr(last, index - last);
		new_content += to_replace;
    	index += to_find.length();
		last = index;
		index = (file_content.find(to_find, index));
	}
	new_content += file_content.substr(last);
	std::cout << new_content << std::endl;
	input_file.close();
	
	return;
}

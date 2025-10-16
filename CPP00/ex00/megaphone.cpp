/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:40:47 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/01 17:07:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	toupper_print(char *line);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++argv && *argv)
		toupper_print(*argv);
}

void	toupper_print(char *line)
{
	while (*line)
	{
		std::cout << (char)std::toupper(*line);
		line++;
	}
}

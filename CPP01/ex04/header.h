#ifndef HEADER_H_
#define HEADER_H_

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:21:06 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 16:42:45 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// _________PARSING____________

void	search_and_destroy(char **argv);
int		file_parsing(std::string filename);
int		parsing(int argc, char **argv);
#endif /* HEADER_H_ */

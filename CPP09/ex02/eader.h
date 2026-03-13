/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eader.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:02 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/13 17:37:20 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EADER_H
# define EADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <cfloat>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <utility>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#define DEBUG 0
#define DBGERR 1
#define MSG(msg) (std::cout << (msg) << std::endl)

bool	valid_chars(char *string);
bool	mainParsing(int argc, char *argv[]);
bool  convert_to_long(char *str, long &result, int line);
void	print_vec_couples(std::vector<std::pair<int, int> > couples);
void	print_stl(std::vector<int> vect);
void	print_stl(std::deque<int> deque);

#if defined(DEBUG) && DEBUG
  #define DBG_MSG(msg) (std::cout << (msg) << std::endl)
#else
  #define DBG_MSG(msg) ((void)0)

#endif

#if defined(DBGERR) && DBGERR
  #define DBG_ERR(...) (std::cerr << __VA_ARGS__ << std::endl);
#else
  #define DBG_ERR(...) ((void)0)

#endif

#endif
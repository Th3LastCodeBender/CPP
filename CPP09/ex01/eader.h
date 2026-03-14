/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eader.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:02 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/14 22:14:51 by lparolis         ###   ########.fr       */
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
#define DEBUG 0
#define EEGG 0
#define MSG(msg) (std::cout << (msg) << std::endl)

size_t	count_operators(std::string input);
size_t	count_digits(std::string input);
bool  	are_chars_valid(std::string input);
bool  	check_order(std::string input);
bool	  is_valid_operator(char c);
bool	  is_valid_char(char c);

#if defined(DEBUG) && DEBUG
  #define DBG_MSG(msg) (std::cout << (msg) << std::endl)
#else
  #define DBG_MSG(msg) ((void)0)

#endif

#if defined(EEGG) && EEGG
  #define EEGG_MSG(msg) (std::cout << (msg) << std::endl);
#else
  #define EEGG_MSG(msg) ((void)0)

#endif

#endif
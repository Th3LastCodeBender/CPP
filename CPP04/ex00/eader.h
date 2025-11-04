/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eader.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:02 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/01 20:58:18 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EADER_H
# define EADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#define PUBIC public
#define ABBLACCINOOOOO public
#define NON_GUALDALEEE private
#define DEBUG 1
#define EEGG 1
#define MSG(msg) (std::cout << (msg) << std::endl)

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
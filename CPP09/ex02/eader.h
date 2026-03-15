/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eader.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:02 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/15 18:56:29 by lparolis         ###   ########.fr       */
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
#include <ctime>
#include <time.h>
#include <deque>
#define DEBUG 0
#define DBGERR 1
#define MSG(msg) (std::cout << (msg) << std::endl)

typedef std::vector<std::pair<int, int> > CoupVec;
typedef std::vector<int>::iterator        vecIt;

//SECTION -  Parsing e utilities
bool	            valid_chars(char *string);
bool	            mainParsing(int argc, char *argv[]);
bool              convert_to_long(char *str, long &result, int line);
void	            print_vec_couples(std::vector<std::pair<int, int> > couples);
void	            print_stl(std::vector<int> vect);
void	            print_stl(std::deque<int> deque);
void	            print_stl(std::vector<int> vect, std::string msg);
void	            print_stl(std::deque<int> deque, std::string msg);
void              print_time(timespec &start, timespec &end, std::string stl, int elements);

//SECTION - Vector part for algorithm
void			          vectorAlgorithm(std::vector<int> &mainVec);
CoupVec			        reorder_pairs_by_max(const std::vector<int> &sorted_max, const CoupVec &pairs);
void				        binary_insert_before_bound(std::vector<int> &vec, int value, size_t bound, std::vector<size_t> &max_positions);
void				        create_pairs(CoupVec &pairs, const std::vector<int> vec);
void				        check_for_struggler(bool has_straggler, int &straggler, std::vector<int> &vec);
std::vector<int>	  vector_create_max_chain(const CoupVec pairs);
void				        handle_straggler(bool has_straggler, int straggler, std::vector<int> &vec);

//SECTION - Deque part for algorithm
void			          dequeAlgorithm(std::deque<int> &mainVec);
CoupVec			        reorder_pairs_by_max(const std::deque<int> &sorted_max, const CoupVec &pairs);
void				        binary_insert_before_bound(std::deque<int> &vec, int value, size_t bound, std::vector<size_t> &max_positions);
void				        create_pairs(CoupVec &pairs, const std::deque<int> &vec);
void				        check_for_struggler(bool has_straggler, int &straggler, std::deque<int> &vec);
std::deque<int>	    deque_create_max_chain(const CoupVec pairs);
void				        handle_straggler(bool has_straggler, int straggler, std::deque<int> &vec);

//SECTION - Common algorithm part
std::vector<size_t>	jacob_insertion_order(size_t n);

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

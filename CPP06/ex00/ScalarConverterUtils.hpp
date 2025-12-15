/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:15:33 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/15 19:24:22 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_UTILS_HPP
#define SCALAR_CONVERTER_UTILS_HPP

#include "eader.h"
#include "ScalarConverter.hpp"

bool specialCases(const std::string &literal);
bool charFinder(const std::string &literal);
bool moreThanOneChar(const std::string &literal, char c);
bool dotAtBeginning(const std::string &literal);
bool dotAtEnd(const std::string &literal);
bool fAtBeginning(const std::string &literal);
bool fAtEnd(const std::string &literal);
bool dotNearF(const std::string &literal);
void formatParsing(const std::string &literal);

#endif

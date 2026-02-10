#ifndef UTILS_HPP
#define UTILS_HPP

#include "eader.h"

bool dateChecker(int line, long int Year, long int Month, long int Day);
bool isLeapYear(long int year);
bool checkValueChars(int line, std::string const &value);
bool checkValueLimits(int line, std::string const &value, char separator);
float convertValue(std::string value);

#endif
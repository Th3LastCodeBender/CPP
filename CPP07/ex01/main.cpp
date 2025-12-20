/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:00:24 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 11:47:02 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "teamplate.hpp"

static void toUpperChar(char &c)
{
    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

static void printInt(const int &x)
{
    std::cout << x << " ";
}

static void incInt(int &x)
{
    ++x;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./Zoo <arg1> [arg2] ..." << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string s(argv[i]);
            if (!s.empty())
                iter(&s[0], s.size(), toUpperChar);
            std::cout << s << std::endl;
        }
    }

    {
        int arr[] = {3, -1, 42, 0, 7};
        std::size_t n = sizeof(arr) / sizeof(arr[0]);

        std::cout << "ints: ";
        iter(arr, n, printInt);
        std::cout << std::endl;

        iter(arr, n, incInt);

        std::cout << "ints+1: ";
        iter(arr, n, printInt);
        std::cout << std::endl;
    }

    return 0;
}
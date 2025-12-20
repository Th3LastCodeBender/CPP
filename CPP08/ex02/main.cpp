/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:56:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 18:22:44 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include "eader.h"
#include <string>

static int g_fail = 0;

static void check(bool cond, const char *msg)
{
    if (!cond)
    {
        ++g_fail;
        std::cout << "[FAIL] " << msg << std::endl;
    }
    else
        std::cout << "[ OK ] " << msg << std::endl;
}

int main(void)
{
    std::cout << "=== CPP07 ex00 tests (C++98) ===" << std::endl;

    // 1) int: swap/min/max
    {
        int a = 2;
        int b = 3;

        ::swap(a, b);
        check(a == 3 && b == 2, "swap(int): swaps values");
        check(::min(a, b) == 2, "min(int): returns min value");
        check(::max(a, b) == 3, "max(int): returns max value");
    }

    // 2) equality rule (value-only)
    {
        int a = 5;
        int b = 5;

        check(::min(a, b) == 5, "min(equal ints): returns 5");
        check(::max(a, b) == 5, "max(equal ints): returns 5");
    }

    // 3) self swap
    {
        int x = 42;
        ::swap(x, x);
        check(x == 42, "swap(x,x): self-swap ok");
    }

    // 4) strings
    {
        std::string c = "chaine1";
        std::string d = "chaine2";

        check(::min(c, d) == "chaine1", "min(string): lexicographic min");
        check(::max(c, d) == "chaine2", "max(string): lexicographic max");

        ::swap(c, d);
        check(c == "chaine2" && d == "chaine1", "swap(string): swaps values");

        std::string x = "same";
        std::string y = "same";
        check(::min(x, y) == "same", "min(equal strings): returns same");
        check(::max(x, y) == "same", "max(equal strings): returns same");
    }

    // 5) chars
    {
        check(::min('z', 'a') == 'a', "min(char): works");
        check(::max('z', 'a') == 'z', "max(char): works");
    }

    std::cout << "=== Result: " << (g_fail == 0 ? "PASS" : "FAIL")
              << " (" << g_fail << " failures) ===" << std::endl;

    return (g_fail == 0 ? 0 : 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:22:19 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 15:16:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include "eader.h"

int main()
{
    std::cout << "===== TEST 1: default constructor =====" << std::endl;
    Array<int> a;
    std::cout << "Size of a: " << a.size() << std::endl;

    std::cout << "\n===== TEST 2: constructor with size =====" << std::endl;
    Array<int> b(5);
    std::cout << "Size of b: " << b.size() << std::endl;

    for (size_t i = 0; i < b.size(); ++i)
        b[i] = static_cast<int>(i * 10);

    for (size_t i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    std::cout << "\n===== TEST 3: copy constructor =====" << std::endl;
    Array<int> c(b);
    std::cout << "Size of c: " << c.size() << std::endl;

    for (size_t i = 0; i < c.size(); ++i)
        std::cout << "c[" << i << "] = " << c[i] << std::endl;

    std::cout << "\nModifying original b..." << std::endl;
    b[0] = 999;

    std::cout << "b[0] = " << b[0] << std::endl;
    std::cout << "c[0] = " << c[0] << " (must NOT change)" << std::endl;

    std::cout << "\n===== TEST 4: copy assignment operator =====" << std::endl;
    Array<int> d;
    d = b;

    std::cout << "Size of d: " << d.size() << std::endl;
    for (size_t i = 0; i < d.size(); ++i)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    std::cout << "\nModifying d..." << std::endl;
    d[1] = 555;

    std::cout << "d[1] = " << d[1] << std::endl;
    std::cout << "b[1] = " << b[1] << " (must NOT change)" << std::endl;

    std::cout << "\n===== TEST 5: out of bounds access =====" << std::endl;
    try
    {
        std::cout << b[100] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: template with another type =====" << std::endl;
    Array<std::string> s(3);
    s[0] = "uno";
    s[1] = "due";
    s[2] = "tre";

    for (size_t i = 0; i < s.size(); ++i)
        std::cout << "s[" << i << "] = " << s[i] << std::endl;

    std::cout << "\n===== END OF TESTS =====" << std::endl;
    return 0;
}
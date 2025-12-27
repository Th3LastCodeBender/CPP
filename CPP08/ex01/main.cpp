/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:56:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/27 18:00:20 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "eader.h"
#include <string>

int main(void)
{
    Span giuorgio(10);

    for (size_t i = 0; i < 10; i++)
        giuorgio.addNumber(std::rand() / 1e8);
    
    std::cout << "ShortestSpan: " << giuorgio.shortestSpan() << std::endl;
    std::cout << "LongestSpan: " << giuorgio.longestSpan() << std::endl;

    // giuorgio.addNumber(30);

    Span franco(0);
    
    franco.addNumber(13);
}

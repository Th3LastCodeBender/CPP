/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:56:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:33 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
    Data data;
    data.id = 71;
    data.content = "Hi, im content";

    Data* originalPtr = &data;
    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << originalPtr << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "OK: non sei buliccio" << std::endl;
    else
        std::cout << "ERRORE: sei un buliccio" << std::endl;

    return 0;
}
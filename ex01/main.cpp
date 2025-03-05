/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:01:17 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/05 19:09:07 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.str = "Old MacDonald had a farm";
	data.i = 536;
	data.f = 536.3f;
	
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	if (&data == deserialized)
		std::cout << "The deserialized pointer points to the same address as the original pointer." << std::endl;
	else
		std::cout << "The deserialized pointer points to a different address than the original pointer." << std::endl;

	std::cout << "Deserialized data:" << std::endl;
	std::cout << "str: " << deserialized->str << std::endl;
	std::cout << "i: " << deserialized->i << std::endl;
	std::cout << "f: " << deserialized->f << std::endl;
	
	return (0);
}	
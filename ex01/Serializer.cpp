/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:33:43 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/05 19:04:25 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	
}

Serializer::Serializer(const Serializer& original)
{
	(void)original;
}

Serializer::~Serializer()
{
	
}

Serializer &Serializer::operator=(const Serializer &original)
{
	(void)original;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr)); // reinterpret is used to convert a pointer to an integer type
}

Data *Serializer::deserialize(uintptr_t raw) 
{
	return (reinterpret_cast<Data *>(raw));
}

//This pair of functions is commonly used to store and retrieve pointers 
//in a safe way when transferring data in a format that does not support raw 
//pointers (e.g., serialization across different contexts, such as file storage, 
//network transmission, or inter-process communication).

//uintptr_t ensures that the conversion does not result in data loss, 
//as it is specifically designed to store pointer values.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:31:27 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/05 19:41:57 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

int main()
{
	Base *base = generate();
	if (!base)
	{
		std::cerr << "Failed to generate object" << std::endl;
		return (1);
	}

	std::cout << "Identifying the type by pointer" << std::endl;
	identify(base);
	std::cout << "Identifying the type by reference" << std::endl;
	identify(*base);
	delete base;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:32 by akovalev          #+#    #+#             */
/*   Updated: 2025/02/04 20:32:56 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	if (argv[1][0] == '\0')
	{
		std::cout << "Error: empty input" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
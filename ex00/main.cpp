/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:32 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/29 17:29:28 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	// ScalarConverter::convert("+inf");	
	// std ::cout << std::endl;
	// ScalarConverter::convert("+inff");	
	// std ::cout << std::endl;
	// ScalarConverter::convert("-inf");
	// std ::cout << std::endl;
	// ScalarConverter::convert("-inff");
	// std ::cout << std::endl;
	// ScalarConverter::convert("nan");
	// std ::cout << std::endl;
	ScalarConverter::convert(argv[1]);
	return (0);
}
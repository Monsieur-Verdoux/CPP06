/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:20:49 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/29 18:16:36 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	(void)original;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
	(void)original;
	return (*this);
}

void ScalarConverter::convert(const std::string& input)
{

	if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nan" || input == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (input == "nanf") 
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		std::cout << "float: " << ((input.back() == 'f' && input.length() == 5) ? input : input + "f") << std::endl;
		std::cout << "double: " << (input.length() == 5 ? input.substr(0, input.size() - 1) : input) << std::endl;
		return;
	}

	if (input.length() == 1 && !isdigit(input[0])) {
		std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
		return ;
	}

	bool is_float = (input.back() == 'f');
	std::string input_without_f = (is_float ? input.substr(0, input.size() - 1) : input);

	char *endptr;
	double d = std::strtod(input_without_f.c_str(), &endptr);

	if (*endptr != '\0') 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) 
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d))) 
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max()) 
		std::cout << "float: impossible" << std::endl;
	else 
	{
		if (d == static_cast<int>(d)) 
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		else 
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	}
	
	if (d == static_cast<int>(d)) 
		std::cout << "double: " << d << ".0" << std::endl;
	else 
		std::cout << "double: " << d << std::endl;
}

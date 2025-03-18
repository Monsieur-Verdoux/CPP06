/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:20:49 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/18 20:40:32 by akovalev         ###   ########.fr       */
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

	if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nan" || input == "nanf" || input == "-nan") 
	{
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

	bool is_char = (input.length() == 1 && !isdigit(input[0]));
	
	bool is_int;
	char *endptr_int;
	char *endptr_dbl;
	char *endptr_float;

	long int_val = std::strtol(input.c_str(), &endptr_int, 10); // strtol converts a string to a long int
	{
		if (*endptr_int == '\0' && int_val >= std::numeric_limits<int>::min() && int_val <= std::numeric_limits<int>::max())
			is_int = true;
		else
			is_int = false;
	}

	bool is_double;
	std::strtod(input.c_str(), &endptr_dbl); // strtod converts a string to a double
	is_double = (*endptr_dbl == '\0');

	bool is_float = (input.back() == 'f');
	std::string input_without_f = (is_float ? input.substr(0, input.size() - 1) : input);

	if (is_char) 
	{
		std::cout << "char: " << "'" <<static_cast<char>(input[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		return ;
	}

	if (is_int) 
	{
		std::cout << "char: ";
		if (int_val < std::numeric_limits<char>::min() || int_val > std::numeric_limits<char>::max() || std::isnan(int_val))
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<char>(std::stoi(input))))
			std::cout << "'" << static_cast<char>(std::stoi(input)) << "'" << std::endl;
		else
			std::cout << "non-displayable" << std::endl;
		std::cout << "int: " << std::stoi(input) << std::endl;
		std::cout << "float: " << static_cast<float>(std::stoi(input)) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(std::stoi(input)) << ".0" << std::endl;
		return ;
	}

	if (is_float) 
	{
		float float_value = std::strtof(input_without_f.c_str(), &endptr_float);
		if (*endptr_float != '\0')
		{
			std:: cout << "char: impossible" << std::endl;
			std:: cout << "int: impossible" << std::endl;
			std:: cout << "float: impossible" << std::endl;
			std:: cout << "double: impossible" << std::endl;
			return ;
		}
		std::cout << "char: ";
		if (float_value < std::numeric_limits<char>::min() || float_value > std::numeric_limits<char>::max() || std::isnan(float_value))
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<char>(float_value)))
			std::cout << "'" << static_cast<char>(float_value) << "'" << std::endl;
		else
			std::cout << "non-displayable" << std::endl;
		std::cout << "int: ";
		if (static_cast<double>(float_value) < std::numeric_limits<int>::min() || static_cast<double>(float_value) > std::numeric_limits<int>::max() || std::isnan(float_value))
			std::cout << "impossible" << std::endl;
		else 
		{
			int int_value = static_cast<int>(float_value);
			std::cout << int_value << std::endl;
		}
		if (float_value == static_cast<int>(float_value))
			std::cout << "float: " << float_value << ".0f" << std::endl;
		else
			std::cout << "float: " << float_value << "f" << std::endl;
		if (float_value == static_cast<int>(float_value))
			std::cout << "double: " << static_cast<double>(float_value) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(float_value) << std::endl;
		return ;
	}

	if (is_double) 
	{
		std::cout << "char: ";
		double double_value = std::strtod(input_without_f.c_str(), &endptr_dbl);
		if (double_value < std::numeric_limits<char>::min() || double_value > std::numeric_limits<char>::max())
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<char>(double_value)))
			std::cout << "'" << static_cast<char>(double_value) << "'" << std::endl;
		else
			std::cout << "non-displayable" << std::endl;
		std::cout << "int: ";
		if (double_value < std::numeric_limits<int>::min() || double_value > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(double_value) << std::endl;
		std::cout << "float: ";
		if (double_value > std::numeric_limits<float>::max())
			std::cout << "inff" << std::endl;
		else if (double_value < std::numeric_limits<float>::lowest())
			std::cout << "-inff" << std::endl;
		else
		{
			if (static_cast<float>(double_value) == static_cast<int>(double_value))
				std::cout << static_cast<float>(double_value) << ".0f" << std::endl;
			else
				std::cout << static_cast<float>(double_value) << "f" << std::endl;
		}
		if (double_value == static_cast<int>(double_value))
			std::cout << "double: " << double_value << ".0" << std::endl;
		else
			std::cout << "double: " << double_value << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

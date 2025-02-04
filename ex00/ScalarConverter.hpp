/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:20:44 by akovalev          #+#    #+#             */
/*   Updated: 2025/02/04 17:45:15 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& original);
		
	public:
		static void convert(const std::string& input); //static means that the function is not associated with any object and can be called on its own
};

#endif
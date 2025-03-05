/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:15:21 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/05 19:42:36 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Base *generate(void)
{
	Base *base = nullptr;
	std::srand(std::time(NULL)); // seed for rand()
	int random = rand() % 3;

	try 
	{
		switch (random)
		{
			case 0:
				std::cout << "A generated" << std::endl;
				base = new A;
				break;
			case 1:
				std::cout << "B generated" << std::endl;
				base = new B;
				break;
			case 2:
				std::cout << "C generated" << std::endl;
				base = new C;
				break;
		}
	} 
	catch (const std::bad_alloc& e) 
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return nullptr;
	}

	return base;
}

//casting pointers returns nullptr if the cast is not possible 
void identify(Base *p)
{
	if (dynamic_cast<A*>(p)) // this checks if the pointer can be cast to A
		std::cout << "Type identified as A by pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type identified as B by pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type identified as C by pointer" << std::endl;
	else
		std::cout << "Type is unknown" << std::endl;
}

//nested try-catch blocks are needed becaus of how dynamic_cast works with references - 
//if the reference cannot be cast to the desired type, it throws an exception

void identify(Base &p) 
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type identified as A by reference" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Type identified as B by reference" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Type identified as C by reference" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "Type is unknown" << std::endl;
			}
		}
	}
}
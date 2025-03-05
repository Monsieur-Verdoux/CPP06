/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:15:28 by akovalev          #+#    #+#             */
/*   Updated: 2025/03/05 19:27:44 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"
#include <iostream>
#include <cstdlib> // needed for rand()
#include <ctime> // needed for time()

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

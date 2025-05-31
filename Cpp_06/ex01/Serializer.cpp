/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:20:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/31 18:12:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Serializer::Serializer()
{
	// std::cout << BOLD BLUE "[Serializer]" RESET BLUE " created" RESET << std::endl;
}

Serializer::Serializer(const Serializer& toCopy)
{
	(void)toCopy;
	// std::cout << BOLD PB "[Serializer]" RESET PB " copy created" RESET << std::endl;
}

Serializer&	Serializer::operator=(const Serializer& toCopy)
{
	(void)toCopy;
	// std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	// std::cout << BOLD PO "[Serializer]" RESET PO " destroyed" RESET << std::endl;
}

/*
	------------------------- [ Main functions ] -------------------------
*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

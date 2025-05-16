/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:15:13 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/16 15:33:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << BOLD DARK_SAND "[IMateriaSource]" RESET DARK_SAND " created"
			  << RESET << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& toCopy)
{
	std::cout << BOLD SAND "[IMateriaSource]" RESET SAND " copy created"
			  << RESET << std::endl;
}

IMateriaSource&		IMateriaSource::operator=(const IMateriaSource& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	std::cout << BOLD ORANGE "[IMateriaSource]" RESET ORANGE " destroyed"
			  << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:05:23 by panther           #+#    #+#             */
/*   Updated: 2025/05/11 05:22:27 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BOLD PG "[Brain]" RESET PG " created"
			  << RESET << std::endl;
}

Brain::Brain(const Brain& toCopy)
{
	std::cout << BOLD PGG "[Brain]" RESET PGG " copy created" RESET
			  << std::endl;
}

Brain&	Brain::operator=(const Brain& toCopy)
{
	std::cout << BOLD PY "[Assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << BOLD RED "[Brain]" RESET RED " destroyed" RESET << std::endl;
}

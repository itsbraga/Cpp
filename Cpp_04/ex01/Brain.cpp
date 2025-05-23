/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:05:23 by panther           #+#    #+#             */
/*   Updated: 2025/05/23 23:22:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "(null)";
	std::cout << BOLD PURPLE "[Brain]" RESET PURPLE " created" RESET << std::endl;
}

Brain::Brain(const Brain& toCopy)
{
	std::cout << BOLD PP "[Brain]" RESET PP " copy created" RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = toCopy.ideas[i];
}

Brain&	Brain::operator=(const Brain& toCopy)
{
	std::cout << BOLD PY "[Copy assignment operator] " RESET "called" << std::endl;
	if (this != &toCopy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = toCopy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << BOLD PY "[Brain]" RESET PY " destroyed" RESET << std::endl;
}

/*
	------------------------- [ Setter & Getter ] ------------------------
*/
void	Brain::setIdea(unsigned int i, std::string idea)
{
	if (idea.empty() == true)
		return ;
	this->ideas[i] = idea;
}

const std::string&	Brain::getIdea(unsigned int i) const
{
	return (this->ideas[i]);
}

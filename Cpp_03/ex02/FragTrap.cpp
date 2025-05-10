/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:56:05 by panther           #+#    #+#             */
/*   Updated: 2025/05/10 20:04:38 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BOLD GREEN "[FragTrap " << name << "]" RESET PG " created"
			  << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << BOLD PG "[FragTrap " << this->_name << "]" RESET
			  << PG " created" RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << BOLD PO "[FragTrap " << this->_name << "]" RESET
			  << PO " destroyed" RESET << std::endl;
}

int		FragTrap::get_hitPoints() const
{
	return (this->_hitPoints);
}

int		FragTrap::get_energyPoints() const
{
	return (this->_energyPoints);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BOLD PP "FragTrap " << this->_name << RESET " attacks "
			  << BOLD PINK << target << RESET ", causing " RED
			  << this->_attackDamage << RESET " points of damage! 🩸"
			  << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << BOLD ORANGE "/!\\ Warning: ";
		if (this->_energyPoints <= 0)
			std::cout << "No energy points left" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "No hit points left" << std::endl;
		std::cout << BOLD BLUE "FragTrap " << this->_name << RESET " can't attack!"
				  << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return ;
	if (this->_hitPoints <= 0)
	{
		std::cout << BOLD PB "FragTrap " << this->_name << RESET
				  << " is already down!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << BOLD PB "FragTrap " << this->_name << RESET " loses " RED
			  << amount << " hit points 🪫" RESET << std::endl;
	std::cout << "Hit points remaining : [" BOLD << get_hitPoints()
			  << RESET "]" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << BOLD RED "FragTrap " << this->_name
				  << " is knocked out!" RESET << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int	maxRepair = 0;

	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (amount == 0)
			return ;
		maxRepair = 100 - this->_hitPoints;
		if (amount > maxRepair)
			this->_hitPoints += maxRepair;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << BOLD ITAL PB "FragTrap " << this->_name
				  << RESET ITAL " is being repaired..." RESET << std::endl;
		std::cout << "Regaining " PG << amount << RESET " hit points 🔋"
				  << std::endl;
	}
	else
	{
		std::cout << BOLD ORANGE "/!\\ Warning: ";
		if (this->_energyPoints <= 0)
			std::cout << "No energy points left" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "No hit points left" << std::endl;
		std::cout << BOLD BLUE "FragTrap " << this->_name << RESET
				  << " can't be repaired!" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Give me a high five my bro!" << std::endl;
}

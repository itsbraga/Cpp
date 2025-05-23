/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:56:05 by panther           #+#    #+#             */
/*   Updated: 2025/05/23 18:00:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
												ScavTrap(name),
												FragTrap(name),
												_name(name)
{
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << BOLD GREEN "[DiamondTrap " << name << "]" RESET PG " created"
			  << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCopy) : ClapTrap(toCopy),
														ScavTrap(toCopy),
														FragTrap(toCopy),
														_name(toCopy._name)
{
	std::cout << BOLD PG "[DiamondTrap " << this->_name << "]" RESET
			  << PG " copy created" RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD PO "[DiamondTrap " << this->_name << "]" RESET
			  << PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Getters ] ----------------------------
*/
const int&	DiamondTrap::get_hitPoints() const
{
	return (this->_hitPoints);
}

const int&	DiamondTrap::get_energyPoints() const
{
	return (this->_energyPoints);
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return ;
	if (this->_hitPoints <= 0)
	{
		std::cout << BOLD PB "DiamondTrap " << this->_name << RESET
				  << " is already down!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << BOLD PB "DiamondTrap " << this->_name << RESET " loses " RED
			  << amount << " hit points 🪫" RESET << std::endl;
	std::cout << "Hit points remaining : [" BOLD << get_hitPoints()
			  << RESET "]" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << BOLD RED "DiamondTrap " << this->_name
				  << " is knocked out!" RESET << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
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
		std::cout << BOLD ITAL PB "DiamondTrap " << this->_name
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
		std::cout << BOLD BLUE "DiamondTrap " << this->_name << RESET
				  << " can't be repaired!" << std::endl;
	}
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " BOLD YELLOW << this->_name << RESET
			  << ", created from " BOLD GREEN << ClapTrap::_name
			  << RESET << std::endl;
}

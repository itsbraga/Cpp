/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:08:54 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 17:26:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BOLD GREEN "[ScavTrap " << name << "]" RESET PG " created"
			  << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << BOLD PG "[ScavTrap " << this->_name << "]" RESET
			  << PG " copy created" RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& toCopy)
{
	if (this != &toCopy)
		ClapTrap::operator=(toCopy);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << BOLD PO "[ScavTrap " << this->_name << "]" RESET
			  << PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Getters ] ----------------------------
*/
const int&	ScavTrap::get_hitPoints() const
{
	return (this->_hitPoints);
}

const int&	ScavTrap::get_energyPoints() const
{
	return (this->_energyPoints);
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BOLD PP "ScavTrap " << this->_name << RESET " attacks "
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
		std::cout << BOLD BLUE "ScavTrap " << this->_name << RESET " can't attack!"
				  << std::endl;
	}
}

void	ScavTrap::takeDamage(uint32_t amount)
{
	if (amount == 0)
		return ;
	if (this->_hitPoints <= 0)
	{
		std::cout << BOLD PB "ScavTrap " << this->_name << RESET
				  << " is already down!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << BOLD PB "ScavTrap " << this->_name << RESET " loses " RED
			  << amount << " hit points 🪫" RESET << std::endl;
	std::cout << "Hit points remaining : [" BOLD << get_hitPoints()
			  << RESET "]" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << BOLD RED "ScavTrap " << this->_name
				  << " is knocked out!" RESET << std::endl;
}

void	ScavTrap::beRepaired(uint32_t amount)
{
	uint32_t	maxRepair = 0;

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
		std::cout << BOLD ITAL PB "ScavTrap " << this->_name
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
		std::cout << BOLD BLUE "ScavTrap " << this->_name << RESET
				  << " can't be repaired!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] is now in " << BOLD PG "Gate keeper" RESET
			  << " mode" << std::endl;
}

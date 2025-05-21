/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:09:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/21 20:15:23 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _energyPoints(10), _attackDamage(0)
{
	std::cout << BOLD PG "[ClapTrap " << name << "]" RESET PG " created"
			  << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy) : _name(toCopy._name),
											 _hitPoints(toCopy._hitPoints),
											 _energyPoints(toCopy._energyPoints),
											 _attackDamage(toCopy._attackDamage)
{
	std::cout << BOLD PGG "[ClapTrap " << this->_name << "]" RESET
			  << PGG " copy created" RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& toCopy)
{
	if (this != &toCopy)
	{
		this->_name = toCopy._name;
		this->_hitPoints = toCopy._hitPoints;
		this->_energyPoints = toCopy._energyPoints;
		this->_attackDamage = toCopy._attackDamage;
	}
	std::cout << BOLD PY "[Copy assignment operator] " RESET << "called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD RED "[ClapTrap " << this->_name << "]" RESET
			  << RED " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Getters ] ----------------------------
*/
const int&	ClapTrap::get_hitPoints() const
{
	return (this->_hitPoints);
}

const int&	ClapTrap::get_energyPoints() const
{
	return (this->_energyPoints);
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BOLD PP "ClapTrap " << this->_name << RESET " attacks "
			  << BOLD PINK << target << RESET ", causing " RED
			  << this->_attackDamage << RESET " points of damage! 🩸" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << BOLD ORANGE "/!\\ Warning: ";
		if (this->_energyPoints <= 0)
			std::cout << "No energy points left" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "No hit points left" << std::endl;
		std::cout << BOLD BLUE "ClapTrap " << this->_name << RESET " can't attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return ;
	if (this->_hitPoints <= 0)
	{
		std::cout << BOLD PB "ClapTrap " << this->_name << RESET
				  << " is already down!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << BOLD PB "ClapTrap " << this->_name << RESET " loses " RED
			  << amount << " hit points 🪫" RESET << std::endl;
	if (this->_hitPoints == 0)
		std::cout << BOLD RED "ClapTrap " << this->_name
				  << " is knocked out!" RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	maxRepair = 0;

	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (amount == 0)
			return ;
		maxRepair = 10 - this->_hitPoints;
		if (amount > maxRepair)
			this->_hitPoints += maxRepair;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << BOLD ITAL PB "ClapTrap " << this->_name
				  << RESET ITAL " is being repaired..." RESET << std::endl;
		std::cout << "Regaining " PG << amount << RESET " hit points 🔋" << std::endl;
	}
	else
	{
		std::cout << BOLD ORANGE "/!\\ Warning: ";
		if (this->_energyPoints <= 0)
			std::cout << "No energy points left" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "No hit points left" << std::endl;
		std::cout << BOLD BLUE "ClapTrap " << this->_name << RESET
				  << " can't be repaired!" << std::endl;
	}
}

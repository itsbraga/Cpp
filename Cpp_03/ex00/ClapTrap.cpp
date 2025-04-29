/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:09:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/29 02:41:06 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _energyPoints(10), _attackDamage(0)
{
	std::cout << BOLD PG "ClapTrap " << name << " created" RESET
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy) : _name(toCopy._name),
											 _hitPoints(toCopy._hitPoints),
											 _energyPoints(toCopy._energyPoints),
											 _attackDamage(toCopy._attackDamage)
{
	std::cout << BOLD PGG "ClapTrap " << this->_name << " created" RESET
			  << std::endl;
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
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD RED "ClapTrap " << this->_name << " destroyed" RESET
			  << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 || this->_hitPoints > 0)
	{
		std::cout << BOLD PP "ClapTrap " << this->_name << RESET " attacks "
			  << target << ", causing " RED << this->_attackDamage
			  << " points of damage! 🩸" RESET << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << BOLD PP "ClapTrap " << this->_name << RESET "can't do "
				  << "anything" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BOLD PB "ClapTrap " << this->_name << RESET " loses " RED
			  << amount << " hit points 🪫" RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 || this->_hitPoints > 0)
	{
		std::cout << BOLD ITAL PB "ClapTrap " << this->_name
				  << RESET ITAL "is being repaired..." RESET << std::endl;
		std::cout << "Its regaining " PG << amount << " hit points 🔋" RESET
				  << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << BOLD PP "ClapTrap " << this->_name << RESET "can't do "
				  << "anything" << std::endl;
}

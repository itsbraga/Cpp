/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:24:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/16 19:45:15 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) : ICharacter(), _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	std::cout << BOLD HOT_PINK "[Character " << this->_name << "]" RESET
			  << HOT_PINK " created" RESET << std::endl;
}

Character::Character(const Character& toCopy) : ICharacter(toCopy), _name(toCopy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (toCopy._inventory[i] != nullptr)
			this->_inventory[i] = toCopy._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	std::cout << BOLD PINK "[Character]" RESET PINK " copy created"
			  << RESET << std::endl;
}

Character&	Character::operator=(const Character& toCopy)
{
	if (this != &toCopy)
	{
		this->_name = toCopy._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != nullptr)
			{
				delete this->_inventory[i];
				this->_inventory[i] = nullptr;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (toCopy._inventory[i] != nullptr)
				this->_inventory[i] = toCopy._inventory[i]->clone();
			else
				this->_inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
	}
	std::cout << BOLD LIGHT_GRAY2 "[Character " << this->_name << "]" RESET
			  << LIGHT_GRAY2 " destroyed" RESET << std::endl;
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}

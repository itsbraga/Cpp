/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:24:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/20 18:18:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character(const std::string& name) : ICharacter(),
												_name(name), _count(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	std::cout << BOLD HOT_PINK "[Character " << this->_name << "]" RESET
			  << HOT_PINK " created" RESET << std::endl;
}

Character::Character(const Character& toCopy) : ICharacter(toCopy),
												_name(toCopy._name),
												_count(toCopy._count)
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
		this->_count = toCopy._count;
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
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called"
			  << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != nullptr)
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
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
	if (m == nullptr || this->_count == 4)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			this->_count++;
			break ;
		}
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == nullptr)
		return ;
	this->_inventory[idx] = nullptr;
	this->_count--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == nullptr)
		return ;
	this->_inventory[idx]->use(target);
}

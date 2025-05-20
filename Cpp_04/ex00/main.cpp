/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/20 16:51:56 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << BOLD "Animal j type: " RESET << j->getType() << " " << std::endl;
	std::cout << BOLD "Animal i type: " RESET << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal*	meta2 = new WrongAnimal();
	const WrongAnimal*	i2 = new WrongCat();

	std::cout << BOLD "Animal i2 type: " RESET << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();

	delete i;
	i = nullptr;
	delete j;
	j = nullptr;
	delete meta;
	meta = nullptr;

	delete i2;
	i2 = nullptr;
	delete meta2;
	meta2 = nullptr;
	return (SUCCESS);
}

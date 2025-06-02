/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/24 17:47:29 by annabrag         ###   ########.fr       */
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

	std::cout << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal*	test = new WrongAnimal();
	const WrongAnimal*	testCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Should not display cat makeSound() func" << std::endl;
	testCat->makeSound();
	std::cout << "Main makeSound() func, from WrongAnimal class" << std::endl;
	test->makeSound();
	std::cout << std::endl;

	delete i;
	i = NULL;
	delete j;
	j = NULL;
	delete meta;
	meta = NULL;

	delete testCat;
	testCat = NULL;
	delete test;
	test = NULL;
	return (SUCCESS);
}

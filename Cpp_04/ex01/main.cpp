/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/24 17:44:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << BOLD "________________ MAIN FROM PROJECT ________________\n"
			  << RESET << std::endl;
	const Animal*	a = new Dog();
	const Animal*	b = new Cat();

	std::cout << "\n";
	a->makeSound();
	b->makeSound();

	std::cout << BOLD "\n-----[ Destroying a and b ]-----\n" << RESET
			  << std::endl;
	delete a; //should not create a leak
	a = NULL;
	delete b;
	b = NULL;

	std::cout << BOLD "\n\n\n_____________________ MY MAIN ______________________\n"
			  << RESET << std::endl;
	Animal*		Animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}

	std::cout << BOLD "\n\n-----[ Testing Deep Copy ]-----\n" << std::endl;
	if (Animals[0] != NULL)
	{
		std::cout << UNDERLINE "  > firstDog" RESET << std::endl;
		Dog*	firstDog = dynamic_cast<Dog*>(Animals[0]);
		if (firstDog)
		{
			std::cout << ITAL "Creating a copy of the first dog..." RESET
					  << std::endl;
			Dog	copyDog = *firstDog; // Stack usage
			
			std::cout << BOLD "\nOriginal dog's ideas:" RESET
					  << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << firstDog->getBrain()->getIdea(j)
						  << std::endl;
			
			std::cout << ITAL "\nModifying copy dog's ideas..." RESET
					  << std::endl;
			copyDog.getBrain()->setIdea(0, "I want cuddles!");
			copyDog.getBrain()->setIdea(1, "Where's my ball?");
			
			std::cout << BOLD "\nCopy dog's ideas after modification:" RESET
					  << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << copyDog.getBrain()->getIdea(j)
						  << std::endl;
			
			std::cout << BOLD "\nOriginal dog's ideas (should be unchanged):"
					  << RESET << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << firstDog->getBrain()->getIdea(j)
						  << std::endl;
			
			std::cout << ITAL "\nDestroying copy dog... " LIGHT_GRAY2
					  << "_stack_" RESET << std::endl;
		}
	}

	if (Animals[1] != NULL)
	{
		std::cout << BOLD UNDERLINE "\n\n  > firstCat" RESET << std::endl;
		Cat*	firstCat = dynamic_cast<Cat*>(Animals[1]);
		if (firstCat)
		{
			std::cout << ITAL "Creating a copy of the first cat..." RESET
					  << std::endl;
			Cat*	copyCat = new Cat(*firstCat); // Heap usage
			
			std::cout << BOLD "\nOriginal cat's ideas:" RESET
					  << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << firstCat->getBrain()->getIdea(j)
						  << std::endl;
			
			std::cout << ITAL "\nModifying copy cat's ideas..." RESET
					  << std::endl;
			copyCat->getBrain()->setIdea(0, "Give me food!");
			copyCat->getBrain()->setIdea(1, "Play with me!");

			std::cout << BOLD "\nCopy cat's ideas after modification:" RESET
					  << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << copyCat->getBrain()->getIdea(j)
						  << std::endl;

			std::cout << BOLD "\nOriginal cat's ideas (should be unchanged):"
					  << RESET << std::endl;
			for (int j = 0; j < 3; j++)
				std::cout << "  - " << firstCat->getBrain()->getIdea(j)
						  << std::endl;

			std::cout << ITAL "\nDestroying copy cat... " LIGHT_GRAY2
					  << "_heap_" RESET << std::endl;
			delete copyCat;
			copyCat = NULL;
		}
	}
	
	std::cout << BOLD "\n\n-----[ Destroying Animals ]-----\n" << RESET
			  << std::endl;
	for (int j = 0; j < 10; j++)
	{
		delete Animals[j];
		Animals[j] = NULL;
	}
	return (SUCCESS);
}

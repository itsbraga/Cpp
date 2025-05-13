/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:32 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/13 18:38:30 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Animal*			Animals[10];
	// const Animal*	j = new Dog();
	// const Animal*	i = new Cat();

	// delete j;
	// delete i;
	// delete [] Animals;
	// Animal*	Animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
		std::cout << BOLD "Created Animal type: " RESET << Animals[i]->getType()
				  << std::endl;
	}

	std::cout << BOLD "\n-----[ Setting and Getting Ideas ]-----\n"
			  << RESET << std::endl;
   if (Animals[0] != NULL)
   {
		Dog*	currDog = dynamic_cast<Dog*>(Animals[0]);
		if (currDog)
		{
			Brain*	dogBrain = currDog->getBrain();
			if (dogBrain)
			{
				dogBrain->setIdea(0, "I love bones!");
				dogBrain->setIdea(1, "Time for a walk!");
				std::cout << BOLD YELLOW "[" << currDog->getType()
							<< " - Animal 0]" RESET << " ideas:" << std::endl;
				for (int j = 0; j < 6; j++)
					std::cout << "  - " << dogBrain->getIdea(j) << std::endl;
			}
		}
	}
	if (Animals[1] != NULL)
	{
		Cat*	currCat = dynamic_cast<Cat*>(Animals[1]);
		if (currCat)
		{
			Brain*	catBrain = currCat->getBrain();
			if (catBrain)
			{
				catBrain->setIdea(0, "Napping is life... Zzzz...");
				catBrain->setIdea(1, "I love you human :3");
				catBrain->setIdea(2, "Pet meeee !!!");
				std::cout << BOLD YELLOW "[" << currCat->getType()
						<< " - Animal 1]" RESET << " ideas:" << std::endl;
				for (int j = 0; j < 6; j++)
					std::cout << "  - " << catBrain->getIdea(j) << std::endl;
			}
		}
	}

	g
	
	std::cout << BOLD "\n-----[ Deleting Animals ]-----\n"
			  << RESET << std::endl;
	for (int j = 0; j < 10; j++)
		delete Animals[j];
	return (SUCCESS);
}

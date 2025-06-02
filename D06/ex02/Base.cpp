/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:47:37 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/02 19:04:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "myBadCast.hpp"

Base::~Base()
{
	// std::cout << BOLD PO "[Base]" RESET PO " destroyed" RESET << std::endl;
}

Base*	generate(void)
{
	static bool	seeded = false;

	if (seeded == false)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	int	random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (new A()); // Toujours gerer le cas default, meme s'il n'est jamais censé arriver
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p) != NULL)
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(&p) != NULL)
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(&p) != NULL)
			std::cout << "C" << std::endl;
		else
			throw myBadCast();
	}
	catch (const myBadCast& e)
	{
		std::cerr << "Unknown type" << std::endl;
		std::cerr << BOLD RED "Exception caught: " RESET << e.what() << std::endl;
	}
}
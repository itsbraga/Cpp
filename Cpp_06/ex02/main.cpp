/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:50:30 by panther           #+#    #+#             */
/*   Updated: 2025/05/31 19:36:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main(int argc, char	**argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << BOLD YELLOW "Usage: " RESET "./identifier" << std::endl;
		return (FAILURE);
	}

	std::cout << BOLD PINK "\n==========[ TESTING RANDOM GENERATION AND IDENTIFICATION ]==========\n" RESET << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << BOLD PGG "\nTest " << i + 1 << ":" RESET << std::endl;

		Base*	obj = generate();
		
		std::cout << "Identification from pointer: ";
		identify(obj);
		
		std::cout << "Identification from reference: ";
		identify(*obj);
		
		delete obj;
		obj = NULL;
	}
	
	std::cout << "\n" BOLD PINK "\n==================[ TESTING WITH SPECIFIC OBJECTS ]=================" RESET << std::endl;
	
	A*	a = new A();
	B*	b = new B();
	C*	c = new C();
	
	std::cout << BOLD PGG "\nTest with A:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(a);
	std::cout << "From reference: ";
	identify(*a);
	
	std::cout << BOLD PGG "\nTest with B:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(b);
	std::cout << "From reference: ";
	identify(*b);
	
	std::cout << BOLD PGG "\nTest with C:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(c);
	std::cout << "From reference: ";
	identify(*c);
	
	std::cout << "\n" BOLD PINK "\n===================[ TESTING WITH BASE* POINTERS ]==================" RESET << std::endl;
	
	Base*	base_a = new A();
	Base*	base_b = new B();
	Base*	base_c = new C();
	
	std::cout << BOLD PP "\nBase* pointing to A:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(base_a);
	std::cout << "From reference: ";
	identify(*base_a);
	
	std::cout << BOLD PP "\nBase* pointing to B:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(base_b);
	std::cout << "From reference: ";
	identify(*base_b);
	
	std::cout << BOLD PP "\nBase* pointing to C:" RESET << std::endl;
	std::cout << "From pointer: ";
	identify(base_c);
	std::cout << "From reference: ";
	identify(*base_c);
	
	std::cout << "\n" BOLD PINK "\n====================[ TESTING WITH NULL POINTER ]===================" RESET << std::endl;

	Base*	null_ptr = NULL;
	
	std::cout << BOLD PP "\nIdentifying NULL Pointer: " RESET;
	identify(null_ptr);
	
	delete a;
	a = NULL;
	delete b;
	b = NULL;
	delete c;
	c = NULL;
	delete base_a;
	base_a = NULL;
	delete base_b;
	base_b = NULL;
	delete base_c;
	base_c = NULL;

	std::cout << BOLD PINK "\n\n==========================[ END OF TESTS ]==========================\n" RESET << std::endl;
	return (SUCCESS);
}

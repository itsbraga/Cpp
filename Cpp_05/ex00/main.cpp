/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 21:25:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << BOLD PGG "\n=============[ CONSTRUCTING BUREAUCRATS ]==============\n" RESET << std::endl;
	
	try
	{
		std::cout << "Creating a normal bureaucrat..." << std::endl;
		Bureaucrat	normal("Jacques", 75);
		std::cout << "Testing insertion operator: " << normal << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nCreating a bureaucrat with grade 0 (too high)..." << std::endl;
		Bureaucrat	tooHigh("Marie", 0);
		std::cout << "This should not print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nCreating a bureaucrat with grade 151 (too low)..." << std::endl;
		Bureaucrat	tooLow("Pierre", 151);
		std::cout << "This should not print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n===========[ TESTING PROMOTION & DEMOTION ]============\n" RESET << std::endl;
	try
	{
		Bureaucrat	bureaucrat("Claudine", 5);
		std::cout << "Initial state: " << bureaucrat << std::endl;
		
		bureaucrat.getPromoted();
		std::cout << "After promotion: " << bureaucrat << std::endl;
		
		bureaucrat.getDemoted();
		std::cout << "After demotion: " << bureaucrat << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nTesting promotion at highest grade..." << std::endl;
		Bureaucrat	highest("Michel", 1);
		std::cout << "Initial state: " << highest << std::endl;
		highest.getPromoted();
		std::cout << "This should not print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\nTesting demotion at lowest grade..." << std::endl;
		Bureaucrat	lowest("Sophie", 150);
		std::cout << "Initial state: " << lowest << std::endl;
		lowest.getDemoted();
		std::cout << "This should not print!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n=============[ TESTING COPY & ASSIGNMENT ]=============\n" RESET << std::endl;
	try
	{
		Bureaucrat	original("Jean", 42);
		std::cout << "Original: " << original << std::endl;
		
		Bureaucrat	copy(original);
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n====================[ END OF TESTS ]===================\n" RESET << std::endl;
	return (SUCCESS);
}

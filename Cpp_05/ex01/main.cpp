/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/27 21:41:58 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << BOLD PGG "\n==============[ CONSTRUCTING BUREAUCRATS ]=============\n" RESET << std::endl;

	try
	{
		Bureaucrat	Boss("Director", 1);
		Bureaucrat	Manager("Manager", 25);
		Bureaucrat	Employee("Employee", 100);
		Bureaucrat	Intern("Intern", 150);
		
		std::cout << "\n" << Boss << std::endl;
		std::cout << Manager << std::endl;
		std::cout << Employee << std::endl;
		std::cout << Intern << std::endl;
		
		std::cout << BOLD PGG "\n\n=================[ CONSTRUCTING FORMS ]================\n" RESET << std::endl;
		
		Form	topSecret("Top Secret Document", 5, 3);
		Form	contract("Employment Contract", 30, 20);
		Form	application("Application Form", 120, 100);
		
		std::cout << "\n" << topSecret << std::endl;
		std::cout << contract << std::endl;
		std::cout << application << std::endl;
		
		std::cout << BOLD PGG "\n\n===================[ SIGNING FORMS ]===================\n" RESET << std::endl;
		
		std::cout << BOLD CYAN "\n__ Testing successful signing __" RESET << std::endl;
		Boss.signForm(topSecret);
		Manager.signForm(contract);
		
		std::cout << BOLD CYAN "\n__ Testing already signed form __" RESET << std::endl;
		try
		{
			Employee.signForm(topSecret);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << BOLD PGG "\n\n=============[ FORM STATUS AFTER SIGNING ]=============\n" RESET << std::endl;
	
		std::cout << "\n" << topSecret << std::endl;
		std::cout << contract << std::endl;
		std::cout << application << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n===================[ END OF TESTS ]====================\n" RESET << std::endl;
	return (SUCCESS);
}

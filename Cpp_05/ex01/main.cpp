/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/23 16:31:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << BOLD PGG "\n=============[ CONSTRUCTING BUREAUCRATS ]=============\n" RESET << std::endl;

	try
	{
		Bureaucrat boss("Director", 1);
		Bureaucrat manager("Manager", 25);
		Bureaucrat employee("Employee", 100);
		Bureaucrat intern("Intern", 150);
		
		std::cout << "\n" << boss << std::endl;
		std::cout << manager << std::endl;
		std::cout << employee << std::endl;
		std::cout << intern << std::endl;
		
		std::cout << BOLD PGG "\n\n=============[ CONSTRUCTING FORMS ]=============\n" RESET << std::endl;
		
		Form topSecret("Top Secret Document");
		Form contract("Employment Contract");
		Form application("Application Form");
		
		std::cout << "\n" << topSecret << std::endl;
		std::cout << contract << std::endl;
		std::cout << application << std::endl;
		
		std::cout << BOLD PGG "\n\n=============[ SIGNING FORMS ]=============\n" RESET << std::endl;
		
		std::cout << BOLD CYAN "\n[Testing successful signing]" RESET << std::endl;
		boss.signForm(topSecret);
		manager.signForm(contract);
		
		std::cout << BOLD CYAN "\n[Testing grade too low]" RESET << std::endl;
		try
		{
			intern.signForm(topSecret);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << BOLD CYAN "\n[Testing already signed form]" RESET << std::endl;
		try
		{
			employee.signForm(topSecret);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << BOLD PGG "\n\n=============[ FORM STATUS AFTER SIGNING ]=============\n" RESET << std::endl;
	
		std::cout << "\n" << topSecret << std::endl;
		std::cout << contract << std::endl;
		std::cout << application << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n===================[ END OF TESTS ]===================\n" RESET << std::endl;
	return (SUCCESS);
}

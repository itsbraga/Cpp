/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/24 21:52:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::cout << BOLD PGG "\n==============[ CONSTRUCTING BUREAUCRATS ]=============\n" RESET << std::endl;

	try
	{
		Bureaucrat Boss("Director", 1);
		Bureaucrat Manager("Manager", 25);
		Bureaucrat Employee("Employee", 100);
		Bureaucrat Intern("Intern", 150);
		
		std::cout << "\n" << Boss << std::endl;
		std::cout << Manager << std::endl;
		std::cout << Employee << std::endl;
		std::cout << Intern << std::endl;
		
		// std::cout << BOLD PGG "\n\n=================[ CONSTRUCTING FORMS ]================\n" RESET << std::endl;
		
		// AForm* Shrubbery = new ShrubberyCreationForm("Top Secret Document", 5, 3);
		// AForm* RobotomyRequest = new RobotomoyRequestForm("Employment Contract", 30, 20);
		// AForm* PresidentialPardon = new PresidentialPardonForm("Application Form", 120, 100);
		
		// std::cout << "\n" << Shrubbery << std::endl;
		// std::cout << RobotomyRequest << std::endl;
		// std::cout << PresidentialPardon << std::endl;
		
		// std::cout << BOLD PGG "\n\n===================[ SIGNING FORMS ]===================\n" RESET << std::endl;
		
		// std::cout << BOLD CYAN "\n[Testing successful signing]" RESET << std::endl;
		// Boss.signForm(Shrubbery);
		// Manager.signForm(RobotomyRequest);
		
		// std::cout << BOLD CYAN "\n[Testing already signed form]" RESET << std::endl;
		// try
		// {
		// 	Employee.signForm(Shrubbery);
		// }
		// catch (std::exception &e)
		// {
		// 	std::cout << e.what() << std::endl;
		// }
		
		// std::cout << BOLD PGG "\n\n=============[ FORM STATUS AFTER SIGNING ]=============\n" RESET << std::endl;
	
		// std::cout << "\n" << Shrubbery << std::endl;
		// std::cout << RobotomyRequest << std::endl;
		// std::cout << PresidentialPardon << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BOLD PGG "\n\n===================[ END OF TESTS ]====================\n" RESET << std::endl;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/15 23:47:21 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << BOLD PGG "\n--------------[ CONSTRUCTING BUREAUCRATS ]-------------\n" RESET << std::endl;

	try {
		Bureaucrat	Boss("Director", 1);
		Bureaucrat	Manager("Manager", 45);
		Bureaucrat	Employee("Employee", 137);
		Bureaucrat	Intern("Intern", 150);

		std::cout << "\n" << Boss << std::endl;
		std::cout << Manager << std::endl;
		std::cout << Employee << std::endl;
		std::cout << Intern << std::endl;

		std::cout << BOLD PGG "\n\n-----------------[ CONSTRUCTING FORMS ]----------------\n" RESET << std::endl;

		ShrubberyCreationForm	Shrub("Home");
		RobotomyRequestForm		Robotomy("Bender");
		PresidentialPardonForm	Pardon("Arthur Dent");

		std::cout << "\n" << Shrub << std::endl;
		std::cout << Robotomy << std::endl;
		std::cout << Pardon << std::endl;

		std::cout << BOLD PGG "\n\n-------------------[ SIGNING FORMS ]-------------------\n" RESET << std::endl;

		std::cout << BOLD CYAN "\n__ Testing successful signing __" RESET << std::endl;
		Employee.signForm(Shrub);
		Manager.signForm(Robotomy);
		Boss.signForm(Pardon);
		
		std::cout << BOLD CYAN "\n__ Testing already signed form __" RESET << std::endl;
		try {
			Intern.signForm(Shrub);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << BOLD PGG "\n\n------------------[ EXECUTING FORMS ]------------------\n" RESET << std::endl;

		std::cout << BOLD CYAN "\n__ Testing successful execution __" RESET << std::endl;
		Employee.executeForm(Shrub);
		Manager.executeForm(Robotomy);
		Boss.executeForm(Pardon);

		std::cout << BOLD CYAN "\n__ Testing too low grade case __" RESET << std::endl;
		try {
			Intern.executeForm(Shrub);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << BOLD CYAN "\n__ Testing not signed form __" RESET << std::endl;
		ShrubberyCreationForm	Shrub2("Neighbor");
		try {
			Manager.executeForm(Shrub2);
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BOLD PGG "\n\n-------------------[ END OF TESTS ]--------------------\n" RESET << std::endl;
	return (SUCCESS);
}

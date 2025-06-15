/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:42:46 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/15 23:48:10 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << BOLD PGG "\n--------------[ CONSTRUCTING BUREAUCRATS ]-------------\n" RESET << std::endl;

	try {
		Bureaucrat	Boss("Director", 1);
		Bureaucrat	Manager("Manager", 45);
		Bureaucrat	Employee("Employee", 137);

		std::cout << "\n" << Boss << std::endl;
		std::cout << Manager << std::endl;
		std::cout << Employee << std::endl;

		std::cout << BOLD PGG "\n\n------------------[ TESTING INTERN ]------------------\n" RESET << std::endl;

		Intern	someRandomIntern;
		AForm*	rrf;

		std::cout << BOLD CYAN "\n__ Testing valid form creation __" RESET << std::endl;
		
		// Test 1: Robotomy Request Form (exemple du sujet)
		rrf = someRandomIntern.makeForm("Robotomy request", "Bender");
		if (rrf)
		{
			std::cout << "\n" << *rrf << std::endl;
			Boss.signForm(*rrf);
			Boss.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf, rrf = NULL;
		}

		std::cout << "\n------------------------------------------------------\n";
		std::cout << BOLD CYAN "\n__ Testing Shrubbery Creation Form __" RESET << std::endl;
		
		// Test 2: Shrubbery Creation Form
		AForm* scf = someRandomIntern.makeForm("Shrubbery creation", "Home");
		if (scf)
		{
			std::cout << "\n" << *scf << std::endl;
			Employee.signForm(*scf);
			Employee.executeForm(*scf);
			std::cout << std::endl;
			delete scf, scf = NULL;
		}

		std::cout << "\n------------------------------------------------------\n";
		std::cout << BOLD CYAN "\n__ Testing Presidential Pardon Form __" RESET << std::endl;
		
		// Test 3: Presidential Pardon Form
		AForm* ppf = someRandomIntern.makeForm("Presidential pardon", "Arthur Dent");
		if (ppf)
		{
			std::cout << "\n" << *ppf << std::endl;
			Boss.signForm(*ppf);
			Boss.executeForm(*ppf);
			std::cout << std::endl;
			delete ppf, ppf = NULL;
		}

		std::cout << "\n------------------------------------------------------\n";
		std::cout << BOLD CYAN "\n__ Testing invalid form creation__" RESET << std::endl;
		
		try {
			AForm* invalidForm = someRandomIntern.makeForm("Invalid form", "Target");
			delete invalidForm, invalidForm = NULL; // Ne devrait jamais être exécuté
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n------------------------------------------------------\n";
		std::cout << BOLD CYAN "\n__ Testing case sensitivity__" RESET << std::endl;
		
		try {
			AForm* invalidForm = someRandomIntern.makeForm("Robotomy Request", "Target");
			delete invalidForm, invalidForm = NULL; // Ne devrait jamais être exécuté
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BOLD PGG "\n\n-------------------[ END OF TESTS ]--------------------\n" RESET << std::endl;
	return (SUCCESS);
}

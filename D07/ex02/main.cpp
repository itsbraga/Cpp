/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 02:02:49 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/03 19:24:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
	std::cout << BOLD PY "Test given by subject: " RESET << std::endl;
	int * a = new int();
	std::cout << "asks to display *a to check its initialization: " RESET << *a << std::endl;
	
	std::cout << BOLD PP "\n========= Default Construction =========" RESET << std::endl;
	
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	std::cout << BOLD PP "\n=========== Size Construction ==========" RESET << std::endl;

	Array<int> numbers(5);
	std::cout << "Array size: " << numbers.size() << std::endl;
	std::cout << "Initial values: ";
	for (uint32_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD PP "\n========== Value Modification ==========" RESET << std::endl;

	for (uint32_t i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	std::cout << "New values: ";
	for (uint32_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD PP "\n=========== Copy Construction ==========" RESET << std::endl;
	
	Array<int> copy(numbers);
	std::cout << "Copy values: ";
	for (uint32_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD PP "\n======= Copy Assignment Operator =======" RESET << std::endl;

	Array<int> LHS;
	LHS = numbers;
	std::cout << "Values after assignment: ";
	for (uint32_t i = 0; i < LHS.size(); i++)
		std::cout << LHS[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD PP "\n======= Independent Modification =======" RESET << std::endl;
	
	numbers[0] = 101010;
	std::cout << "Original after modification: " << numbers[0] << std::endl;
	std::cout << "Copy after modification: " << copy[0] << std::endl;
	std::cout << "Assigned after modification: " << LHS[0] << std::endl;

	std::cout << BOLD PP "\n========= Different Type Test ==========" RESET << std::endl;
	
	Array<std::string> strs(3);
	strs[0] = "Qui pense peu,";
	strs[1] = "se trompe beaucoup.";
	strs[2] = "Askiparaaaiiit";
	std::cout << "String array: ";
	for (uint32_t i = 0; i < strs.size(); i++)
		std::cout << strs[i] << " ";
	std::cout << std::endl;

	std::cout << BOLD PP "\n=========== Index Error Test ===========" RESET << std::endl;
	
	try
	{
		std::cout << "Attempting to access index 10: ";
		numbers[10];
	}
	catch (const std::exception& e)
	{
		std::cout << BOLD RED "Exception caught: " RESET "Index out of bounds" << std::endl;
	}
	std::cout << std::endl;
	return (SUCCESS);
}

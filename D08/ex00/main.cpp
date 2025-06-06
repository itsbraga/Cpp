/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:39:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/06 19:26:10 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void	testVector()
{
	std::cout << BOLD PP "\n=======[ Testing with std::vector ]=======" RESET << std::endl;
	
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(7);
	vec.push_back(100);
	vec.push_back(42); // dup to check first occurrence --> std::find

	std::cout << "Vector contents: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		std::vector<int>::iterator result = easyfind(vec, 42);
		std::cout << PG "Found value " << *result << " at position: "
				  << std::distance(vec.begin(), result) << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator result = easyfind(vec, 999);
		std::cout << PG "Found value " << *result << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << " (999)" << std::endl;
	}
}

void	testList()
{
	std::cout << BOLD PP "\n========[ Testing with std::list ]========" RESET << std::endl;
	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		std::list<int>::iterator result = easyfind(lst, 30);
		std::cout << PG "Found value " << *result << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator result = easyfind(lst, 15);
		std::cout << PG "Found value " << *result << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << " (15)" << std::endl;
	}
}

void	testDeque()
{
	std::cout << BOLD PP "\n========[ Testing with std::deque ]=======" RESET << std::endl;
	
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(15);
	deq.push_back(25);

	std::cout << "Deque contents: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		std::deque<int>::iterator result = easyfind(deq, 15);
		std::cout << PG "Found value " << *result << " at position: "
				  << std::distance(deq.begin(), result) << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << std::endl;
	}
}

void	testConstContainer()
{
	std::cout << BOLD PP "\n=====[ Testing with const container ]=====" RESET << std::endl;
	
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	
	const std::vector<int> const_vec = vec;

	std::cout << "Const vector contents: ";
	for (std::vector<int>::const_iterator it = const_vec.begin(); it != const_vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		std::vector<int>::const_iterator result = easyfind(const_vec, 200);
		std::cout << PG "Found value " << *result << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << std::endl;
	}
}

void	testEmptyContainer()
{
	std::cout << BOLD PP "\n=====[ Testing with empty container ]=====" RESET << std::endl;
	
	std::vector<int> empty_vec;

	try {
		std::vector<int>::iterator result = easyfind(empty_vec, 42);
		std::cout << PG "Found value " << *result << " in empty container" RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << BOLD RED "Error: " RESET << e.what() << " (42)" << std::endl;
	}

	std::cout << std::endl;
}

int	main( void )
{
	testVector();
	testList();
	testDeque();
	testConstContainer();
	testEmptyContainer();
	return (SUCCESS);
}

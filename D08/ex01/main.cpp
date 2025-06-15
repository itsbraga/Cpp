/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:39:25 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/15 23:36:17 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <ctime>

void	testExceptions()
{
	std::cout << BOLD "\n-----------[ Test exceptions ]----------" RESET << std::endl;
	
	// Test Span too small
	{
		Span sp = Span(2);
		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3); // Should throw an exception
			std::cout << BOLD RED "Error: " RESET "Exception not thrown when adding too many numbers" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << BOLD PG "Success: " RESET << e.what() << std::endl;
		}
	}

	// Test Span empty
	{
		Span sp = Span(5);
		try {
			sp.shortestSpan(); // Should throw an exception
			std::cout << BOLD RED "Error: " RESET "Exception not thrown when calculating span with no numbers" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << BOLD PG "Success: " RESET << e.what() << std::endl;
		}
	}

	// Test Span with one number
	{
		Span sp = Span(5);
		try {
			sp.addNumber(42);
			sp.longestSpan(); // Should throw an exception
			std::cout << BOLD RED "Error: " RESET "Exception not thrown when calculating span with one number" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << BOLD PG "Success: " RESET << e.what() << std::endl;
		}
	}
}

void	testSmallSpan()
{
	std::cout << BOLD "\n---------[ Test with 3 numbers]---------" RESET << std::endl;
	
	Span sp = Span(3);
	std::vector<int> vec;
	vec.push_back(-10);
	vec.push_back(0);
	vec.push_back(10);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

void	testMediumSpan()
{
	std::cout << BOLD "\n---------[ Test with 10 numbers]--------" RESET << std::endl;
	
	Span sp = Span(10);
	std::vector<int> vec;
	vec.push_back(1000000);		// 1,000,000
	vec.push_back(-1000000);	// -1,000,000
	vec.push_back(0);
	vec.push_back(42);
	vec.push_back(-42);
	vec.push_back(100);
	vec.push_back(-100);		// -100
	vec.push_back(1000);		// 1,000
	vec.push_back(-1000);		// -1,000
	vec.push_back(500);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

void	testLargeSpan()
{
	std::cout << BOLD "\n-------[ Test with 1,000 numbers]-------" RESET << std::endl;
	
	Span sp = Span(1000);
	std::vector<int> vec;
	
	for (int i = 0; i < 1000; i++)
		vec.push_back(i * 10);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

void	testXLargeSpan()
{
	std::cout << BOLD "\n------[ Test with 10,000 numbers ]------" RESET << std::endl;
	
	Span sp = Span(10000);
	std::vector<int> vec;
	
	for (int i = 0; i < 10000; i++)
		vec.push_back(i * 2);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

void	testHugeSpan()
{
	std::cout << BOLD "\n------[ Test with 100,000 numbers]------" RESET << std::endl;
	
	Span sp = Span(100000);
	std::vector<int> vec;
	
	for (int i = 0; i < 100000; i++)
		vec.push_back(i);

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

void	testRandomSpan()
{
	std::cout << BOLD "\n-----[ Test with 50 random values ]-----" RESET << std::endl;
	
	Span sp = Span(50);
	std::vector<int> vec;
	
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
		vec.push_back(rand() % 1000 - 500); // Values between -500 and 499

	sp.addRange(vec.begin(), vec.end());
	
	std::cout << BOLD PP "Shortest span: " RESET << sp.shortestSpan() << std::endl;
	std::cout << BOLD PINK "Longest span: " RESET << sp.longestSpan() << std::endl;
}

int	main( void )
{
	std::cout << BOLD "________________ MAIN FROM PROJECT ________________\n" << RESET << std::endl;

	Span *sp = new Span(5);
	sp->addNumber(6);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(11);

	std::cout << sp->shortestSpan() << std::endl;
	std::cout << sp->longestSpan() << std::endl;
	delete sp;

	std::cout << BOLD "\n\n_____________________ MY MAIN ______________________\n" << RESET << std::endl;

	try {
		testExceptions();
		testSmallSpan();
		testMediumSpan();
		testLargeSpan();
		testXLargeSpan();
		testHugeSpan();
		testRandomSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

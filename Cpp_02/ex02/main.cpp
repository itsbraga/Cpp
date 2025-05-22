/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:27:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/05/22 19:21:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void)
// {
// 	Fixed		a;
// 	Fixed const	b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;

// 	return (SUCCESS);
// }

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		std::cout << BOLD RED "Error: " RESET "Wrong amount of arguments" << std::endl;
		return (FAILURE);
	}
	try
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));
		Fixed		c(Fixed(5.05f) * Fixed(2));
		Fixed		d(24.02f);
		Fixed		e(91);

		std::cout << a << " > " << b << " ?\n";
		if (a > b)
			std::cout << "true " << a <<  " > " << b << "\n";
		else
			std::cout << "false " << a <<  " < " << b << "\n";

		std::cout << "\n" << a << " < " << b << " ?\n";
		if (a < b)
			std::cout << "true " << a <<  " < " << b << "\n";
		else
			std::cout << "false " << a <<  " > " << b << "\n";

		std::cout << "\n" << a << " >= " << b << " ?\n";
		if (a >= b)
			std::cout << "true " << a <<  " >= " << b << "\n";
		else
			std::cout << "false " << a <<  " <= " << b << "\n";

		std::cout << "\n" << a << " <= " << b << " ?\n";
		if (a <= b)
			std::cout << "true " << a <<  " <= " << b << "\n";
		else
			std::cout << "false " << a <<  " >= " << b << "\n";

		std::cout << "\n" << a << " == " << b << " ?\n";
		if (a == b)
			std::cout << "true " << a <<  " == " << b << "\n";
		else
			std::cout << "false " << a <<  " != " << b << "\n";

		std::cout << "\n" << a << " != " << b << " ?\n";
		if (a != b)
			std::cout << "true " << a <<  " != " << b << "\n\n";
		else
			std::cout << "false " << a <<  " == " << b << "\n\n";

		std::cout << a << " + 2 = " << (a + 2) << " \n";
		std::cout << a << " - 2 = " << (a - 2) << " \n";
		std::cout << a << " * 2 = " << (a * 2) << " \n";
		std::cout << e << " * 0.9f = " << (e * 0.9f) << " \n";
		std::cout << e << " * 0.3f = " << (e * 0.3f) << " \n";
		std::cout << e << " * 3 = " << (e * 3) << " \n";
		std::cout << e << " + 10 = " << (e + 10) << " \n";
		std::cout << e << " - 10 = " << (e - 10) << " \n";
		std::cout << e << " / 10 = " << (e / 10) << " \n";
		std::cout << e << " / 0.9f = " << (e / 0.9f) << " \n";
		// std::cout << e << " / 0 = " << (e / 0) << " \n";

		std::cout << a << " / 2 = " << (a / 2)  << " \n\n";
		std::cout <<  "a is " << a << std::endl;
		std::cout << "++a is " << ++a << std::endl;
		std::cout <<  "a is " << a << std::endl;
		std::cout <<  "a++ is " << a++ << std::endl;
		std::cout <<  "a is " << a << std::endl;
		std::cout << "--a is " << --a << std::endl;
		std::cout <<  "a is " << a << std::endl;
		std::cout <<  "a-- is " << a-- << std::endl;
		std::cout <<  "a is " << a << "\n\n";
		std::cout <<  "b is " << b << "\n\n";
		std::cout << "Min is: "  << Fixed::min(a, c) << "\n";
		std::cout << "Min const is: "  << Fixed::min(a, b) << "\n";
		std::cout << "Min is: "  << Fixed::min(d, e) << "\n";
		std::cout << "Min const is: "  << Fixed::min(d, e) << "\n\n";
		std::cout << "Max is: " << Fixed::max(a, c) << "\n";
		std::cout << "Max const is: " << Fixed::max(a, b) << "\n";
		std::cout << "Max is: " << Fixed::max(d, e) << "\n";
		std::cout << "Max const is: " << Fixed::max(d, e) << "\n";
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		return (FAILURE);
	}
	return (SUCCESS);
}

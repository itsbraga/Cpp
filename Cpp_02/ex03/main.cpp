/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:27:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/04/29 01:57:54 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	__print_bsp_result(const std::string& label, bool result)
{
	std::cout << label;
	if (result == true)
		std::cout << BOLD PG "True" RESET << std::endl;
	else
		std::cout << BOLD RED "False" RESET << std::endl;
}

int main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	// Point strictement à l'intérieur
	Point	p1(2, 2);
	__print_bsp_result("p1 (2,2) inside ? ", bsp(a, b, c, p1));

	// Point sur un sommet
	Point	p2(0, 0);
	__print_bsp_result("p2 (0,0) on vertex ? ", bsp(a, b, c, p2));

	// Point sur un bord
	Point	p3(5, 0);
	__print_bsp_result("p3 (5,0) on edge ? ", bsp(a, b, c, p3));

	// Point à l'extérieur
	Point	p4(10, 10);
	__print_bsp_result("p4 (10,10) outside ? ", bsp(a, b, c, p4));

	// Point très proche du bord mais à l'intérieur
	Point	p5(0.01f, 0.01f);
	__print_bsp_result("p5 (0.01,0.01) inside (near edge) ? ", bsp(a, b, c, p5));

	// Point sur l'autre bord
	Point	p6(0, 5);
	__print_bsp_result("p6 (0,5) on edge ? ", bsp(a, b, c, p6));

	// Point à l'intérieur d'un triangle rectangle
	Point	p7(3, 3);
	__print_bsp_result("p7 (3,3) inside ? ", bsp(a, b, c, p7));

	// Point sur l'hypoténuse
	Point	p8(5, 5);
	__print_bsp_result("p8 (5,5) on hypotenuse ? ", bsp(a, b, c, p8));

	return (SUCCESS);
}

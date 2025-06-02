/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:16:30 by panther           #+#    #+#             */
/*   Updated: 2025/06/02 17:59:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BOLD PY "Usage: " RESET "./ScalarConverter <literal>" << std::endl;
		return (FAILURE);
	}

	std::cout << BOLD PGG "=======[ ScalarConverter Test ]=======" RESET << std::endl;
	std::cout << YELLOW "\nInput: " RESET "\"" << argv[1] << "\"" << std::endl;
	std::cout << PG "\n--- Conversions ---\n" RESET << std::endl;

	ScalarConverter::convert(argv[1]);
	return (SUCCESS);
}

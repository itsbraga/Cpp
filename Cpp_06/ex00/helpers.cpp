/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:41:13 by panther           #+#    #+#             */
/*   Updated: 2025/05/31 21:01:54 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(const std::string& literal)
{
	if (literal.empty() == true)
		return (false);
	if (literal.length() == 1)
	{
		char c = literal[0];
		if (c >= '0' && c <= '9')
			return (false);
		return (c >= 32 && c <= 126);
	}
	return (false);
}

bool	isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal.empty() == true)
		return (false);
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (i == literal.length())
		return (false);

	for (; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]) == false)
			return (false);
	}
	return (true);
}

bool	isFloat(const std::string& literal)
{
	std::string	nbr;
	size_t		i = 0;
	bool		hasDot = false;

	if (literal.empty() == true)
		return (false);
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal[literal.length() - 1] != 'f')
		return (false);

	nbr = literal.substr(0, literal.length() - 1);
	if (nbr.empty() == true)
		return (false);
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	if (i == nbr.length())
		return (false);

	for (; i < nbr.length(); i++)
	{
		if (nbr[i] == '.')
		{
			if (hasDot == true)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(nbr[i]) == false)
			return (false);
	}
	return (hasDot && std::isdigit(nbr[nbr.length() - 1]));
}

bool	isDouble(const std::string& literal)
{
	size_t		i = 0;
	bool		hasDot = false;

	if (literal.empty() == true)
		return (false);
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (i == literal.length())
		return (false);

	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot == true)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(literal[i]) == false)
			return (false);
	}
	return (hasDot && std::isdigit(literal[literal.length() - 1]));
}

bool	isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}

void	handleSpecialFloat(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	handleSpecialDouble(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

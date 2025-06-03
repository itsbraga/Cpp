/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:41:13 by panther           #+#    #+#             */
/*   Updated: 2025/06/03 18:37:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
	----------------------- [ Type detection ] ---------------------------
*/
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
		return (false);
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
		return (false);
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

bool	isSpecialFloat(const std::string& literal)
{
	return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool	isSpecialDouble(const std::string& literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

/*
	---------------------- [ Special handling ] --------------------------
*/
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

/*
	---------------------- [ Display functions ] -------------------------
*/
void	displayChar(double value)
{
	if (value < 0 || value > 127 || value != static_cast<int>(value)
		|| std::isnan(value) == true || std::isinf(value) == true)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	displayInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()
		|| std::isnan(value) == true || std::isinf(value) == true)
		std::cout << "int: " BOLD RED "out of range" RESET << std::endl;
	else if (value != static_cast<int>(value))
		std::cout << "int: " BOLD RED "impossible" RESET << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	displayFloat(double value)
{
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "float: " BOLD RED "out of range" RESET << std::endl;
	else
	{
		float f = static_cast<float>(value);
		if (static_cast<double>(f) != value)
			std::cout << "float: " BOLD PO "imprecise" RESET << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1)
					  << "float: " << f << "f" << std::endl;
	}
}

void	displayDouble(double value)
{
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		std::cout << "double: " BOLD RED "out of range" RESET << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1)
				  << "double: " << value << std::endl;
}

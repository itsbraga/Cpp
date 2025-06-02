/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:04:17 by panther           #+#    #+#             */
/*   Updated: 2025/06/02 18:29:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
	Note : Constructors and destructor are in private to prevent instantiation
*/
ScalarConverter::ScalarConverter()
{
	// std::cout << BOLD BLUE "[ScalarConverter]" RESET BLUE " created" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy)
{
	(void)toCopy;
	// std::cout << BOLD PB "[ScalarConverter]" RESET PB " copy created" RESET << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	(void)toCopy;
	// std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << BOLD PO "[ScalarConverter]" RESET PO " destroyed" RESET << std::endl;
}

/*
	------------------------ [ Type detection ] --------------------------
*/
static LiteralType	__detectType(const std::string& literal)
{
	if (isChar(literal) == true)
		return (CHAR);
	else if (isInt(literal) == true)
		return (INT);
	else if (isFloat(literal) == true)
		return (FLOAT);
	else if (isDouble(literal) == true)
		return (DOUBLE);
	else if (isSpecialFloat(literal) == true)
		return (SPECIALFLOAT);
	else if (isSpecialDouble(literal) == true)
		return (SPECIALDOUBLE);
	return (UNKNOWN);
}

static void	__convertFromChar(const std::string& literal)
{
	char c = literal[0];
	displayChar(static_cast<double>(c));
	displayInt(static_cast<double>(c));
	displayFloat(static_cast<double>(c));
	displayDouble(static_cast<double>(c));
}

static void	__convertFromInt(const std::string& literal)
{
	std::istringstream iss(literal);
	long value;
	char leftover;

	if (!(iss >> value) || (iss >> leftover))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	displayChar(static_cast<double>(value));
	displayInt(static_cast<double>(value));
	displayFloat(static_cast<double>(value));
	displayDouble(static_cast<double>(value));
}

static void	__convertFromFloat(const std::string& literal)
{
	std::string tmp = literal.substr(0, literal.length() - 1);
	std::istringstream iss(tmp);
	float value;
	char leftover;

	if (!(iss >> value) || (iss >> leftover))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	displayChar(static_cast<double>(value));
	displayInt(static_cast<double>(value));
	displayFloat(static_cast<double>(value));
	displayDouble(static_cast<double>(value));
}

static void	__convertFromDouble(const std::string& literal)
{
	std::istringstream iss(literal);
	double value;
	char leftover;

	if (!(iss >> value) || (iss >> leftover))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = __detectType(literal);

	if (type == SPECIALFLOAT)
		return (handleSpecialFloat(literal));
	else if (type == SPECIALDOUBLE)
		return (handleSpecialDouble(literal));
	else if (type == CHAR)
		__convertFromChar(literal);
	else if (type == INT)
		__convertFromInt(literal);
	else if (type == FLOAT)
		__convertFromFloat(literal);
	else if (type == DOUBLE)
		__convertFromDouble(literal);
	else if (type == UNKNOWN)
		std::cerr << BOLD RED "Error: " RESET "Unknown literal type" << std::endl;
}
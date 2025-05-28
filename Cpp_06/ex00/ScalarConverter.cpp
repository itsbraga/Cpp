/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:04:17 by panther           #+#    #+#             */
/*   Updated: 2025/05/28 21:50:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
	Note : Constructors and destructor are in private to prevent instantiation
*/
ScalarConverter::ScalarConverter()
{
	std::cout << BOLD BLUE "[ScalarConverter]" RESET BLUE " created" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PB "[ScalarConverter]" RESET PB " copy created" RESET << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	(void)toCopy;
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << BOLD PO "[ScalarConverter]" RESET PO " destroyed" RESET << std::endl;
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
	return (UNKNOWN);
}

/*
	----------------------- [ Print functions ] --------------------------
*/
static void	__printAllImpossible()
{
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible" << std::endl;
}

static void	__printChar(double v)
{
	if (std::isnan(v) || v < 0 || v > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(v);
		std::cout << "char: "
				  << (isDisplayable(c) ? std::string("'") + c + "'" : "Non displayable")
				  << std::endl;
	}
}

static void	__printInt(double v)
{
	if (std::isnan(v) || std::isinf(v))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(v) << std::endl;
}

static void	__printFloat(double v)
{
	if (std::isnan(v) || std::isinf(v))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "
				  << std::fixed << std::setprecision(1)
				  << static_cast<float>(v) << "f" << std::endl;
}

static void	__printDouble(double v)
{
	if (std::isnan(v) || std::isinf(v))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: "
				  << std::fixed << std::setprecision(1)
				  << v << std::endl;
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = __detectType(literal);

	if (type == FLOAT && (literal == "nanf" || literal == "+inff" || literal == "-inff"))
		return (handleSpecialFloat(literal));
	if (type == DOUBLE && (literal == "nan"  || literal == "+inf"  || literal == "-inf"))
		return (handleSpecialDouble(literal));

	std::istringstream iss(literal);
	double value = 0.0;

	switch (type)
	{
		case CHAR:
		{
			char c;
			iss >> c;
			value = c;
			break ;
		}
		case INT:
		{
			int i;
			iss >> i;
			if (iss.fail() == true)
				return (__printAllImpossible());
			value = i;
			break ;
		}
		case FLOAT:
		{
			float f;
			iss >> f;
			if (iss.fail() == true)
				return (__printAllImpossible());
			value = f;
			break ;
		}
		case DOUBLE:
		{
			iss >> value;
			if (iss.fail() == true)
				return (__printAllImpossible());
			break ;
		}
		default:
			return (__printAllImpossible());
	}
	__printChar(value);
	__printInt(value);
	__printFloat(value);
	__printDouble(value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:04:17 by panther           #+#    #+#             */
/*   Updated: 2025/05/28 01:31:59 by panther          ###   ########.fr       */
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
	-------------------------- [ Conversion ] ----------------------------
*/
void	ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c)
			  << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c)
			  << std::endl;
}

void	ScalarConverter::convertFromInt(int value)
{
	if (value < 0 || value > 127)
		std::cerr << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (isDisplayable(c) == false)
			std::cerr << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

	std::cout << "int: " << value << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)
			  << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)
			  << std::endl;
}

void	ScalarConverter::convertFromFloat(float value)
{
	if (value < 0.0f || value > 127.0f || value != static_cast<int>(value))
		std::cerr << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (isDisplayable(c) == false)
			std::cerr << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cerr << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)
			  << std::endl;
}

void	ScalarConverter::convertFromDouble(double value)
{
	if (value < 0.0 || value > 127.0 || value != static_cast<int>(value))
		std::cerr << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (isDisplayable(c) == false)
			std::cerr << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cerr << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cerr << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)
				  << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

/*
	---------------- [ Shortened conversion functions ] ------------------
*/
void	ScalarConverter::getChar(const std::string& literal)
{
	char c = literal[1];
	convertFromChar(c);
}

void	ScalarConverter::getInt(const std::string& literal)
{
	try
	{
		long tmp = std::stol(literal);
		if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
			std::cerr << BOLD RED "Error: " RESET "Integer overflow" << std::endl;
		else
			convertFromInt(static_cast<int>(tmp));
	}
	catch (std::exception &e)
	{
		std::cerr << BOLD RED "Error: " RESET "Invalid integer" << std::endl;
	}
}

void	ScalarConverter::getFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		handleSpecialFloat(literal);
	else
	{
		try
		{
			float value = std::stof(literal);
			convertFromFloat(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD RED "Error: " RESET "Invalid float" << std::endl;
		}
	}
}

void	ScalarConverter::getDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		handleSpecialDouble(literal);
	else
	{
		try
		{
			double value = std::stod(literal);
			convertFromDouble(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD RED "Error: " RESET "Invalid double" << std::endl;
		}
	}
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal) == true)
		getChar(literal);
	else if (isInt(literal) == true)
		getInt(literal);
	else if (isFloat(literal) == true)
		getFloat(literal);
	else if (isDouble(literal) == true)
		getDouble(literal);
	else
		std::cerr << BOLD RED "Error: " RESET "Unknown literal type" << std::endl;
}

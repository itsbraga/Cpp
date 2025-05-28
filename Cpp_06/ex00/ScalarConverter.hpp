/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:57:39 by panther           #+#    #+#             */
/*   Updated: 2025/05/28 21:28:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

enum LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>
# include <iomanip>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& toCopy);
			ScalarConverter&	operator=(const ScalarConverter& toCopy);
			~ScalarConverter();

	public:
			static void		convert(const std::string& literal);
};

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

bool		isChar(const std::string& literal);
bool		isInt(const std::string& literal);
bool		isFloat(const std::string& literal);
bool		isDouble(const std::string& literal);
bool		isDisplayable(char c);

void		handleSpecialFloat(const std::string& literal);
void		handleSpecialDouble(const std::string& literal);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:57:39 by panther           #+#    #+#             */
/*   Updated: 2025/05/28 01:31:40 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include <string>
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

			static bool		isChar(const std::string& literal);
			static bool		isInt(const std::string& literal);
			static bool		isFloat(const std::string& literal);
			static bool		isDouble(const std::string& literal);
			static bool		isDisplayable(char c);
			
			static void		handleSpecialFloat(const std::string& literal);
			static void		handleSpecialDouble(const std::string& literal);
		
			static void		convertFromChar(char c);
			static void		convertFromInt(int value);
			static void		convertFromFloat(float value);
			static void		convertFromDouble(double value);

			static void		getChar(const std::string& literal);
			static void		getInt(const std::string& literal);
			static void		getFloat(const std::string& literal);
			static void		getDouble(const std::string& literal);

	public:
			static void		convert(const std::string& literal);
};

#endif
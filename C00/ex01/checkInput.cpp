/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkInput.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:36:10 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/09 19:08:10 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool	__checkWithSpecialChar(std::string input)
{
	int	digit_count = 0;
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i % 3 == 2)
		{
			if (input[i] != ' ' && input[i] != '-' && input[i] != '.')
			{
				std::cout << ERR_PREFIX "Invalid format" << std::endl;
				std::cout << "Phone number format must be as follows:" << std::endl;
				std::cout << "1) XX XX XX XX XX" << std::endl;
				std::cout << "2) XX-XX-XX-XX-XX" << std::endl;
				std::cout << "3) XX.XX.XX.XX.XX" << std::endl;
				return (false);
			}
		}
		else
		{
			if (std::isdigit(input[i]) == false)
			{
				std::cout << ERR_PREFIX "Phone number can only contain digits"
							<< std::endl;
				return (false);
			}
			digit_count++;
		}
	}
	return (true);
}

static bool	__checkNumericField(std::string input)
{
	// Version sans espaces (ex: 0653351965)
	if (input.length() == 10)
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (std::isdigit(input[i]) == false)
			{
				std::cout << ERR_PREFIX "Phone number can only contain digits"
						  << std::endl;
                return (false);
			}
		}
		return (true);
	}
	// Version avec espaces, tirets ou points
	else if (input.length() == 14)
	{
		if (__checkWithSpecialChar(input) == false)
			return (false);
	}
	else
	{
		std::cout << ERR_PREFIX "Invalid format" << std::endl;
		std::cout << "Phone number must be in format:" << std::endl;
		std::cout << "1) XXXXXXXXXX" << std::endl << "2) XX XX XX XX XX" << std::endl;
		std::cout << "3) XX-XX-XX-XX-XX" << std::endl << "4) XX.XX.XX.XX.XX" << std::endl;
		return (false);
	}
}

static bool	__checkAlphaFields(std::string input)
{
	if (std::isspace(input[0]) == true || input[0] == '-')
	{
		std::cout << ERR_PREFIX "First word cannot start with space or hyphen"
				  << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isalpha(input[i]) == false && input[i] != '-' && input[i] != ' ')
		{
			std::cout << ERR_PREFIX "Words can only contain letters, spaces and hyphen"
					  << std::endl;
			return (false);
		}
		if (i > 0 && (input[i] == '-' || input[i] == ' '))
		{
			if (input[i - 1] == '-' || input[i - 1] == ' ')
			{
				std::cout << ERR_PREFIX "Cannot have consecutive spaces or hyphens"
						  << std::endl;
				return (false);
			}
		}
	}
	if (input.back() == '-' || input.back() == ' ')
	{
		std::cout << ERR_PREFIX "Word cannot end with space or hyphen"
				  << std::endl;
		return (false);
	}
	return (true);
}

bool	checkInput(std::string input, std::string field)
{
	if (input.empty() == true)
	{
		std::cout << ERR_PREFIX "All fields must be filled" << std::endl;
		return (false);
	}
	if (field == "phone_nb")
	{
		if (__checkNumericField(input) == false)
			return (false);
	}
	else
	{
		if (__checkAlphaFields(input) == false)
			return (false);
	}
	return (true);
}

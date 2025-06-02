/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:16:30 by panther           #+#    #+#             */
/*   Updated: 2025/06/01 22:50:58 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char	**argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << BOLD YELLOW "Usage: " RESET "./serializer" << std::endl;
		return (FAILURE);
	}

	std::cout << BOLD PGG "=======[ Serializer Test ]=======" RESET << std::endl;
	
	Data	originalData;
	originalData.name = "Mr Robot";
	Data*	originalPtr = &originalData;
	
	std::cout << PY "\nOriginal address: " RESET << originalPtr << std::endl;
	std::cout << PY "Original name: " RESET "\"" << originalData.name << "\"" << std::endl;
	
	uintptr_t	serialized = Serializer::serialize(originalPtr);
	Data*		deserializedPtr = Serializer::deserialize(serialized);
	
	std::cout << BLUE "Serialized: " RESET << serialized << std::endl;
	std::cout << PG "Deserialized: " RESET << deserializedPtr << std::endl;
	
	bool	pointersEqual;
	bool	dataAccessible;
	
	if (originalPtr == deserializedPtr)
		pointersEqual = true;
	else
		pointersEqual = false;

	if (deserializedPtr != NULL && deserializedPtr->name == "Mr Robot")
		dataAccessible = true;
	else
		dataAccessible = false;
	
	std::cout << BOLD "\n--- Results ---" RESET << std::endl;
	std::cout << "Pointers equal: " << (pointersEqual ? BOLD PG "✓ YES" : BOLD RED "✗ NO")
			  << RESET << std::endl;
	std::cout << "Data accessible: " << (dataAccessible ? BOLD PG "✓ YES" : BOLD RED "✗ NO")
			  << RESET << std::endl;
	std::cout << "Final status: " << (pointersEqual && dataAccessible ? BOLD PG "SUCCESS" : BOLD RED "FAILURE")
			  << RESET << std::endl;
	
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:16:30 by panther           #+#    #+#             */
/*   Updated: 2025/06/15 23:43:52 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	std::cout << BOLD PGG "-------[ Serializer Test ]-------" RESET << std::endl;
	
	Data originalData;
	originalData.name	= "Mr Robot";
	Data* originalPtr	= &originalData;
	
	std::cout << PY "\nOriginal address: " RESET << originalPtr << std::endl;
	std::cout << PY "Original name: " RESET "\"" << originalData.name << "\"" << std::endl;
	
	uintptr_t serialized	= Serializer::serialize(originalPtr);
	Data* deserializedPtr	= Serializer::deserialize(serialized);
	
	std::cout << BLUE "Serialized: " RESET << serialized << std::endl;
	std::cout << PG "Deserialized: " RESET << deserializedPtr << std::endl;
	
	bool pointersEqual;
	bool dataAccessible;
	
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
	
	originalData.age	= 42;
	originalData.note	= 18.5;

	std::cout << BOLD PGG "\n-------[ Extended Tests with Age and Note ]-------" RESET << std::endl;
	
	std::cout << PY "\nOriginal complete data:" RESET << std::endl;
	std::cout << "  Name: \"" << originalData.name << "\"" << std::endl;
	std::cout << "  Age: " << originalData.age << std::endl;
	std::cout << "  Note: " << originalData.note << std::endl;
	
	uintptr_t serialized2	= Serializer::serialize(originalPtr);
	Data* deserializedPtr2	= Serializer::deserialize(serialized2);
	
	std::cout << BLUE "\nAfter serialization/deserialization:" RESET << std::endl;
	std::cout << "  Name: \"" << deserializedPtr2->name << "\"" << std::endl;
	std::cout << "  Age: " << deserializedPtr2->age << std::endl;
	std::cout << "  Note: " << deserializedPtr2->note << std::endl;
	
	bool nameCorrect		= (deserializedPtr2->name == "Mr Robot");
	bool ageCorrect			= (deserializedPtr2->age == 42);
	bool noteCorrect		= (deserializedPtr2->note == 18.5);
	bool allFieldsCorrect	= nameCorrect && ageCorrect && noteCorrect;
	
	std::cout << BOLD "\n--- Extended Results ---" RESET << std::endl;
	std::cout << "Name correct: " << (nameCorrect ? BOLD PG "✓ YES" : BOLD RED "✗ NO")
			  << RESET << std::endl;
	std::cout << "Age correct: " << (ageCorrect ? BOLD PG "✓ YES" : BOLD RED "✗ NO")
			  << RESET << std::endl;
	std::cout << "Note correct: " << (noteCorrect ? BOLD PG "✓ YES" : BOLD RED "✗ NO")
			  << RESET << std::endl;
	std::cout << "All fields intact: " << (allFieldsCorrect ? BOLD PG "✓ SUCCESS" : BOLD RED "✗ FAILURE")
			  << RESET << std::endl;
	
	std::cout << BOLD PGG "\n-------[ Test with Different Values ]-------" RESET << std::endl;
	
	Data testData2;
	testData2.name	= "Elliot Alderson";
	testData2.age	= 28;
	testData2.note	= 19.75;
	Data* testPtr2	= &testData2;
	
	std::cout << PY "\nSecond test data:" RESET << std::endl;
	std::cout << "  Name: \"" << testData2.name << "\"" << std::endl;
	std::cout << "  Age: " << testData2.age << std::endl;
	std::cout << "  Note: " << testData2.note << std::endl;
	
	uintptr_t	serialized3 = Serializer::serialize(testPtr2);
	Data*		deserializedPtr3 = Serializer::deserialize(serialized3);
	
	bool	test2Valid = (testPtr2 == deserializedPtr3 && 
						  deserializedPtr3->name == "Elliot Alderson" &&
						  deserializedPtr3->age == 28 &&
						  deserializedPtr3->note == 19.75);
	
	std::cout << "Second test result: " << (test2Valid ? BOLD PG "✓ SUCCESS" : BOLD RED "✗ FAILURE")
			  << RESET << std::endl;
	
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:43:06 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/16 00:03:35 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

void	mainFromProject()
{
	std::cout << BOLD "________________ MAIN FROM PROJECT ________________\n" << RESET << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "\nIterating through MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	testWithList()
{
	std::cout << BOLD "\n\n_____________________ MY MAIN ______________________\n" << RESET << std::endl;

	std::cout << BOLD PY "----------[ Test with list ]----------" RESET << std::endl;
	
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Back: " << lst.back() << std::endl;
	
	lst.pop_back();
	
	std::cout << "Size: " << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	
	++it;
	--it;
	
	std::cout << "\nIterating through list:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	testAdditionalFeatures()
{
	std::cout << BOLD PY "\n----------[ Additional tests ]----------" RESET << std::endl;
	
	// Test with strings
	MutantStack<std::string> strStack;
	
	strStack.push("We.");
	strStack.push("Live.");
	strStack.push("In.");
	strStack.push("A Simulation.");
	
	std::cout << "String Stack (forward iterator):" << std::endl;
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n\n";

	// Test with const iterator
	const MutantStack<std::string>	constStack = strStack;
	std::cout << "Const Stack (const iterator):" << std::endl;
	for (MutantStack<std::string>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
	
	// Test with reverse iterator
	std::cout << "\nString Stack (reverse iterator):" << std::endl;
	for (MutantStack<std::string>::reverse_iterator rit = strStack.rbegin(); rit != strStack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << "\n\n";
	
	// Test copy constructor
	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	
	MutantStack<int> copy(original);
	std::cout << "Original stack: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Copy stack: ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n\n";
	
	// Test assignment operator
	MutantStack<int> assigned;
	assigned = original;
	std::cout << "Assigned stack: ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main( void )
{
	mainFromProject();
	testWithList();
	testAdditionalFeatures();
	return (SUCCESS);
}

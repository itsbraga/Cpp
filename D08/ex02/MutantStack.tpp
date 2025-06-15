/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:55:44 by panther           #+#    #+#             */
/*   Updated: 2025/06/15 23:31:07 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template< typename T >
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << BOLD PGG "[Template 'MutantStack']" RESET PGG " created"
			  << RESET << std::endl;
}

template< typename T >
MutantStack<T>::MutantStack( const MutantStack<T>& toCopy ) : std::stack<T>(toCopy)
{
	std::cout << BOLD PB "[Template 'MutantStack']" RESET PB " copy created"
			  << RESET << std::endl;
}

template< typename T >
MutantStack<T>&		MutantStack<T>::operator=( const MutantStack<T>& toCopy )
{
	std::cout << BOLD PY "[Template copy assignment operator]" RESET PY << " called"
			  << RESET << std::endl;
	if (this != &toCopy)
		std::stack<T>::operator=(toCopy);
	return (*this);
}

template< typename T >
MutantStack<T>::~MutantStack()
{
	std::cout << BOLD PO "[Template 'MutantStack']" RESET PO " destroyed"
			  << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:55:44 by panther           #+#    #+#             */
/*   Updated: 2025/06/16 00:35:36 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
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

/*
	---------------------------- [ Iterators ] ---------------------------
*/
template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template< typename T >
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template< typename T >
typename MutantStack<T>::const_iterator		MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template< typename T >
typename MutantStack<T>::const_iterator		MutantStack<T>::end() const
{
	return (this->c.end());
}

template< typename T >
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template< typename T >
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (this->c.rend());
}

template< typename T >
typename MutantStack<T>::const_reverse_iterator		MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template< typename T >
typename MutantStack<T>::const_reverse_iterator		MutantStack<T>::rend() const
{
	return (this->c.rend());
}

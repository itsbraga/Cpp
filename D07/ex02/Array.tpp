/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 01:44:09 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/16 00:31:13 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
template< typename T >
Array<T>::Array() : _array(NULL), _size(0)
{
	// std::cout << BOLD PGG "[Template 'Array']" RESET PGG " created"
	// 		  << RESET << std::endl;
}

template< typename T >
Array<T>::Array( uint32_t n ) : _size(n)
{
	// std::cout << BOLD PG "[Template 'Array' with size]" RESET PG " created"
	// 		  << RESET << std::endl;
	this->_array = new T[n](); // () --> initialization by default
}

template< typename T >
Array<T>::Array( const Array<T>& toCopy ) : _size(toCopy._size)
{
	// std::cout << BOLD PB "[Template 'Array']" RESET PB " copy created"
	// 		  << RESET << std::endl;
	this->_array = new T[this->_size]();

	for (uint32_t i = 0; i < this->_size; i++)
		this->_array[i] = toCopy._array[i];
}

template< typename T >
Array<T>&		Array<T>::operator=( const Array<T>& toCopy )
{
	// std::cout << BOLD PY "[Template copy assignment operator]" RESET PY << " called"
	// 		  << RESET << std::endl;
	if (this != &toCopy)
	{
		delete [] this->_array;
		this->_size = toCopy._size;
		this->_array = new T[this->_size]();

		for (uint32_t i = 0; i < this->_size; i++)
			this->_array[i] = toCopy._array[i];
	}
	return (*this);
}

template< typename T >
Array<T>::~Array()
{
	// std::cout << BOLD PO "[Template 'Array']" RESET PO " destroyed" 
	// 		  << RESET << std::endl;
	delete [] this->_array;
}

/*
	----------------------- [ Operator overload ] ------------------------
*/
template< typename T >
T&	Array<T>::operator[]( uint32_t index )
{
	if (index >= this->_size)
		throw OutOfBoundsException();
	return (this->_array[index]);
}

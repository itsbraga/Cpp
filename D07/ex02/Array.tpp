/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 01:44:09 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/03 19:21:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template< typename T >
Array<T>::Array() : _array(NULL), _size(0)
{
	// std::cout << BOLD PGG "[Template 'Array']" RESET PGG " created" RESET << std::endl;
}

template< typename T >
Array<T>::Array( uint32_t n ) : _size(n)
{
	// std::cout << BOLD PG "[Template 'Array' with size]" RESET PG " created" RESET << std::endl;
	this->_array = new T[n](); // () --> initialization by default
}

template< typename T >
Array<T>::Array( const Array& toCopy ) : _size(toCopy._size)
{
	// std::cout << BOLD PB "[Template 'Array']" RESET PB " copy created" RESET << std::endl;
	this->_array = new T[this->_size]();

	for (uint32_t i = 0; i < this->_size; i++)
		this->_array[i] = toCopy._array[i];
}

template< typename T >
Array<T>& Array<T>::operator=( const Array& toCopy )
{
	// std::cout << BOLD PY "[Template copy assignment operator]" RESET << " called" << std::endl;
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
	// std::cout << BOLD PO "[Template 'Array']" RESET PO " destroyed" RESET << std::endl;
	delete [] this->_array;
}

template< typename T >
T&	Array<T>::operator[]( uint32_t index )
{
	if (index >= this->_size)
		throw OutOfBoundsException();
	return (this->_array[index]);
}

template< typename T >
const T&	Array<T>::operator[]( uint32_t index ) const
{
	if (index >= this->_size)
		throw OutOfBoundsException();
	return (this->_array[index]);
}

template< typename T >
const uint32_t&		Array<T>::size() const
{
	return (this->_size);
}
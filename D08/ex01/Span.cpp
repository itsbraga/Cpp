/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:43:47 by panther           #+#    #+#             */
/*   Updated: 2025/06/15 22:24:15 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( uint32_t N ) : _N(N)
{
	std::cout << BOLD PURPLE "[Span]" RESET PURPLE " created" RESET << std::endl;
}

Span::Span( const Span& toCopy )
{
	std::cout << BOLD PP "[Span]" RESET PP " copy created" RESET << std::endl;
	*this = toCopy;
}

Span&	Span::operator=( const Span& toCopy )
{
	std::cout << BOLD PY "[Copy assignment operator]" RESET << " called" << std::endl;
	if (this != &toCopy)
		this->_N = toCopy._N;
	return (*this);
}

Span::~Span()
{
	std::cout << BOLD PO "[Span]" RESET PO " destroyed" RESET << std::endl;
}

void	Span::addNumber( int number )
{
	if (this->_vec.size() >= this->_N)
		throw SpanIsFullException();
	this->_vec.push_back(number);
}

uint32_t	Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw SpanNotEnoughException();

	std::sort( this->_vec.begin(), this->_vec.end() );
	uint32_t shortest = std::abs( this->_vec[1] - this->_vec[0] );
	
	for (size_t i = 1; i < this->_vec.size() - 1; i++)
	{
		uint32_t curr_diff = std::abs( this->_vec[i + 1] - this->_vec[i] );
		if (curr_diff < shortest)
			shortest = curr_diff;
	}
	return (shortest);
}

uint32_t	Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw SpanNotEnoughException();

	std::sort( this->_vec.begin(), this->_vec.end() );
	uint32_t max_diff = std::abs( this->_vec.back() - this->_vec.front() );
	return (max_diff);
}
